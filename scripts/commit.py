#!/usr/bin/env python3
"""半自动 jj 提交：按 ctime 排序本次完成的题目，预填提交信息。用法：just commit"""

import re
import subprocess
import sys
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def changed_solutions() -> list[Path]:
    out = subprocess.run(
        ["jj", "diff", "-r", "@", "--name-only"],
        cwd=ROOT,
        capture_output=True,
        text=True,
        check=True,
    ).stdout
    files = []
    for line in out.splitlines():
        p = ROOT / line.strip()
        if p.suffix == ".cpp" and p.parent.name == "solutions" and p.exists():
            files.append(p)
    # 按 ctime 升序 = 实际完成顺序
    return sorted(files, key=lambda p: p.stat().st_ctime)


def main() -> int:
    files = changed_solutions()
    if not files:
        print("working copy 中没有 solutions/*.cpp 改动", file=sys.stderr)
        return 1
    ids = [re.match(r"(\d+)", f.name).group(1) for f in files]  # type: ignore[union-attr]
    today = date.today().isoformat()
    msg = f"{today}({len(ids)}): 完成 T{', '.join(ids)}"
    print("预填提交信息：", msg)
    print("完成顺序（ctime）：", " → ".join(f.name for f in files))
    # -m 预填后仍开编辑器供修改
    subprocess.run(["jj", "commit", "--editor", "-m", msg], cwd=ROOT, check=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
