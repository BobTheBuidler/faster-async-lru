from typing import Generic, TypeVar


__all__ = ("_NonNativeClass",)


_R = TypeVar("_R")

class _NonNativeClass(Generic[_R]):
    """This class only exists as a workaround to the fact
    that native classes have no __dict__, but we need our
    wrappers to have it.
    """
