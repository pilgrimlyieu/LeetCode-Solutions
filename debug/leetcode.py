"""GDB helpers for this LeetCode workspace."""

import pathlib
import re

import gdb


ROOT = pathlib.Path(__file__).resolve().parents[1]
SOLUTIONS = ROOT / "solutions"
USER_METHOD_RE = re.compile(r"^[A-Z][A-Za-z0-9_]*::")


def _function_name() -> str:
    try:
        name = gdb.selected_frame().name()
    except gdb.error:
        return ""
    return name or ""


def _source_path() -> pathlib.Path | None:
    try:
        symtab = gdb.selected_frame().find_sal().symtab
    except gdb.error:
        return None
    if symtab is None:
        return None
    try:
        return pathlib.Path(symtab.fullname()).resolve()
    except RuntimeError:
        return pathlib.Path(symtab.filename).resolve()


def _in_solutions(path: pathlib.Path | None) -> bool:
    if path is None:
        return False
    try:
        path.relative_to(SOLUTIONS)
    except ValueError:
        return False
    return True


def _is_user_method_frame() -> bool:
    return USER_METHOD_RE.match(_function_name()) is not None and _in_solutions(
        _source_path()
    )


def _is_solution_breakpoint(bp: gdb.Breakpoint) -> bool:
    if bp.pending:
        return False
    for loc in bp.locations:
        source = getattr(loc, "source", None)
        if not source:
            continue
        path = pathlib.Path(source[0]).resolve()
        if _in_solutions(path):
            return True
    return False


class LeetCodeStep(gdb.Command):
    """Step into a Solution method on the current statement, otherwise next."""

    def __init__(self) -> None:
        super().__init__("lc-step", gdb.COMMAND_RUNNING)

    def invoke(self, arg: str, from_tty: bool) -> None:
        if _is_user_method_frame():
            gdb.execute("step", from_tty=False, to_string=True)
            return

        breakpoints = []
        try:
            before = {bp.number for bp in gdb.breakpoints() or []}
            gdb.execute(
                "rbreak ^[A-Z][A-Za-z0-9_]*::.*", from_tty=False, to_string=True
            )
            created = [bp for bp in gdb.breakpoints() or [] if bp.number not in before]
            for bp in created:
                if _is_solution_breakpoint(bp):
                    bp.silent = True
                    breakpoints.append(bp)
                else:
                    bp.delete()
            if not breakpoints:
                gdb.execute("next", from_tty=False, to_string=True)
                return
            gdb.execute("next", from_tty=False, to_string=True)
        finally:
            for bp in breakpoints:
                if bp.is_valid():
                    bp.delete()


LeetCodeStep()
