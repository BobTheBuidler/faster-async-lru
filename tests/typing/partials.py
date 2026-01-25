"""Mypy-only checks for functools.partial and partialmethod support."""

from __future__ import annotations

from functools import partial, partialmethod
from typing import Optional, Union

from faster_async_lru import _LRUCacheWrapper, _LRUCacheWrapperInstanceMethod, alru_cache

from typing_extensions import assert_type


async def base(value: int, suffix: str) -> str:
    return f"{value}{suffix}"


partial_func = partial(base, 1)
partial_wrapped = alru_cache(partial_func)

assert_type(partial_wrapped, _LRUCacheWrapper[str])


class Handler:
    async def build(self, value: int, suffix: str) -> str:
        return f"{value}{suffix}"

    cached_build = alru_cache(partialmethod(build, 2))

    async def build_kw(self, value: int, *, suffix: str) -> str:
        return f"{value}{suffix}"

    cached_build_kw = alru_cache(partialmethod(build_kw, 3, suffix="z"))


handler = Handler()

assert_type(
    Handler.cached_build,
    Union[
        _LRUCacheWrapper[str],
        _LRUCacheWrapperInstanceMethod[str, Optional[Handler]],
    ],
)
assert_type(
    handler.cached_build,
    Union[_LRUCacheWrapper[str], _LRUCacheWrapperInstanceMethod[str, Handler]],
)
assert_type(
    handler.cached_build_kw,
    Union[_LRUCacheWrapper[str], _LRUCacheWrapperInstanceMethod[str, Handler]],
)


async def _check_call_results() -> None:
    partial_result = await partial_wrapped("x")
    assert_type(partial_result, str)

    handler_result = await handler.cached_build("y")
    assert_type(handler_result, str)

    handler_kw_result = await handler.cached_build_kw()
    assert_type(handler_kw_result, str)
