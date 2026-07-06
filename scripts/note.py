#!/usr/bin/env python3
"""从 notes/template.typ 实例化题目笔记。用法：just note 239"""

import json
import re
import sys
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CACHE = Path.home() / ".cache/nvim/leetcode/problemlist_cn"


def load_meta(frontend_id: str) -> dict:
    """从 leetcode.nvim 缓存取题目元数据；缓存缺失时留空占位。"""
    meta = {"title": "", "slug": "", "difficulty": ""}
    try:
        data = json.loads(CACHE.read_text(encoding="utf-8"))["data"]
    except (OSError, KeyError, json.JSONDecodeError):
        return meta
    for q in data:
        if str(q.get("frontend_id")) == frontend_id:
            meta["title"] = q.get("title_cn") or q.get("title") or ""
            meta["slug"] = q.get("title_slug", "")
            meta["difficulty"] = q.get("difficulty", "")
            break
    return meta


def main() -> int:
    if len(sys.argv) != 2:
        print("usage: note.py <frontend_id | solution-path>", file=sys.stderr)
        return 2
    arg = sys.argv[1]
    m = re.match(r"(\d+)", Path(arg).name)
    if not m:
        print(f"cannot parse question id from {arg!r}", file=sys.stderr)
        return 2
    qid = m.group(1)

    meta = load_meta(qid)
    stem = f"{qid}.{meta['slug']}" if meta["slug"] else qid
    dest = ROOT / "notes" / f"{stem}.typ"
    if not dest.exists():
        text = (ROOT / "notes" / "template.typ").read_text(encoding="utf-8")
        for key, val in {
            "{{ID}}": qid,
            "{{TITLE}}": meta["title"],
            "{{SLUG}}": meta["slug"],
            "{{DIFFICULTY}}": meta["difficulty"],
            "{{DATE}}": date.today().isoformat(),
        }.items():
            text = text.replace(key, val)
        dest.write_text(text, encoding="utf-8")
    print(f"{dest}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
