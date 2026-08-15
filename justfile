# LeetCode 本地工具链。用法示例：
#   just run 239        按题号编译运行（ASan/UBSan + CHECK）
#   just run solutions/239.sliding-window-maximum.cpp
#   just debug 239      无 sanitizer 编译（供 gdb/DAP），stdout 末行输出产物路径
#   just build-all      全量编译回归
#   just stats          重生成 README 进度表
#   just note 239       从模板创建 Typst 笔记
#   just commit         半自动 jj 提交（按 mtime 排序完成列表）
#   just anki push     制作/更新 Anki 卡片（子模块，见 anki/justfile）

# Anki 制卡子模块（anki/ 为独立 jj 仓库，根仓库不追踪）
mod? anki

root := justfile_directory()
build := root / "build"

cxx := "g++"
flags := `xargs < compile_flags.txt`
debug_flags := "-g3 -O0 -fno-omit-frame-pointer"
san := "-fsanitize=address,undefined"

# 默认：裸 just 列出所有命令
_default:
    @just --list --unsorted

# 题号或路径 → solutions/*.cpp 唯一匹配（内部配方）
[private]
_resolve F:
    #!/usr/bin/env zsh
    set -euo pipefail
    f="{{ F }}"
    if [[ -f "$f" ]]; then print -r -- "${f:A}"; exit 0; fi
    matches=(solutions/"$f".*.cpp(N))
    if (( ${#matches} == 0 )); then
        print -u2 "no solution matches '$f'"; exit 1
    elif (( ${#matches} > 1 )); then
        print -u2 "ambiguous: ${matches[@]}"; exit 1
    fi
    print -r -- "${matches[1]}"

# 编译运行（LeetCode 题解不释放节点，关闭 LeakSanitizer 防误报）
run F:
    #!/usr/bin/env zsh
    set -euo pipefail
    src=$(just _resolve "{{ F }}")
    mkdir -p "{{ build }}"
    out="{{ build }}/${${src:t}%.cpp}"
    {{ cxx }} {{ flags }} {{ san }} "$src" -o "$out"
    ASAN_OPTIONS=detect_leaks=0 "$out"

# check 是 run 的语义化别名（CHECK 失败即非零退出，供脚本判定）
check F: (run F)

# 无 sanitizer 编译供 gdb/DAP；stdout 最后一行为产物路径（nvim 键位读取）
debug F:
    #!/usr/bin/env zsh
    set -euo pipefail
    src=$(just _resolve "{{ F }}")
    mkdir -p "{{ build }}"
    out="{{ build }}/${${src:t}%.cpp}.dbg"
    {{ cxx }} {{ flags }} {{ debug_flags }} "$src" -o "$out"
    print -r -- "$out"

# 全量编译（迁移验证 / utils.h 改动回归）。只编译不运行
build-all:
    #!/usr/bin/env zsh
    set -euo pipefail
    autoload -U zargs
    mkdir -p "{{ build }}"
    fail=0
    parallel -j $(nproc) --bar '{{ cxx }} {{ flags }} -fdiagnostics-color=always -fsyntax-only {} || exit 1' ::: solutions/*.cpp(N)
    (( fail == 0 )) && print "build-all: all green" || print -u2 "build-all: some files failed"

# utils.h 回归测试
test-utils:
    #!/usr/bin/env zsh
    set -euo pipefail
    mkdir -p "{{ build }}"
    {{ cxx }} {{ flags }} {{ san }} scripts/test_check.cpp -o "{{ build }}/test_check"
    ASAN_OPTIONS=detect_leaks=0 "{{ build }}/test_check"

# CHECK 生成器（scripts/gen_checks.py）单测
test-gen:
    @cd scripts && python3 test_gen_checks.py

# 重生成 README 进度表
stats:
    @python3 scripts/stats.py

# 从模板创建 Typst 笔记（notes/<id>.<slug>.typ）
note F:
    @python3 scripts/note.py "{{ F }}"

# 半自动 jj 提交（完成列表按 mtime 排序，编辑器内补 W?D?）
commit:
    @python3 scripts/commit.py
