from typing import Generic

from typing_extensions import TypeVarTuple, Unpack


__all__ = ("_NonNativeClass",)


_T = TypeVarTuple("_T")

class _NonNativeClass(Generic[Unpack[_T]]):
    """
    A generic class that can accept any number and type of type arguments.

    Example usage:
        _NonNativeClass[int]
        _NonNativeClass[int, str]
        _NonNativeClass[int, str, float]
        # etc.

    This class only exists as a workaround to the fact
    that native classes have no __dict__, but we need our
    wrappers to have it.
    """
