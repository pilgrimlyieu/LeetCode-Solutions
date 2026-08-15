-- leetcode.nvim 的 question_enter hook：把 main() 中的 `// @TESTAUTOGEN` 标记行
-- 替换为按题生成的 CHECK 行（生成逻辑见同目录 gen_checks.py）。
-- 标记被替换后即消失，天然幂等；旧题解无标记，不受影响。
-- 由 ~/.config/nvim/lua/plugins/leetcode.lua 以 dofile 加载。

local py_script = debug.getinfo(1, "S").source:sub(2):gsub("%.lua$", ".py")

local function find_marker(bufnr)
	local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
	for i, line in ipairs(lines) do
		if line:match("^%s*//%s*@TESTAUTOGEN%s*$") then
			return i
		end
	end
end

---@param q lc.ui.Question
return function(q)
	if q.lang ~= "cpp" or not q.q then
		return
	end
	if not (q.bufnr and vim.api.nvim_buf_is_valid(q.bufnr)) then
		return
	end
	if not find_marker(q.bufnr) then
		return
	end

	local payload = vim.json.encode({
		meta_data = q.q.meta_data,
		testcase_list = q.q.testcase_list,
		translated_content = q.q.translated_content,
		content = q.q.content,
	})

	-- 异步生成，不阻塞 UI；回调里重新定位标记，容忍等待期间的编辑
	vim.system({ "python3", py_script }, { stdin = payload, text = true }, function(res)
		vim.schedule(function()
			if res.code ~= 0 then
				local msg = "gen_checks.py 失败: " .. (res.stderr or "")
				vim.notify(msg, vim.log.levels.WARN, { title = "leetcode" })
				return
			end
			if not (q.bufnr and vim.api.nvim_buf_is_valid(q.bufnr)) then
				return
			end
			local marker = find_marker(q.bufnr)
			local out = vim.split(res.stdout or "", "\n", { trimempty = true })
			if marker and #out > 0 then
				vim.api.nvim_buf_set_lines(q.bufnr, marker - 1, marker, false, out)
			end
		end)
	end)
end
