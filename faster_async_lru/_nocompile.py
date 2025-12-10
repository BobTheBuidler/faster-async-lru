from typing import Generic

from typing_extensions import TypeVarTuple, Unpack


__all__ = ("_NonNativeClass",)


_T = TypeVarTuple("_")

class _NonNativeClass(Generic[Unpack[_T]]):
    """This class only exists as a workaround to the fact
    that native classes have no __dict__, but we need our
    wrappers to have it.
    """
