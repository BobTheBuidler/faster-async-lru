"""Mypy-only checks for descriptor access and explicit __get__ usage."""

from __future__ import annotations

from typing import Optional, Union

from faster_async_lru import _LRUCacheWrapper, _LRUCacheWrapperInstanceMethod, alru_cache

from typing_extensions import assert_type


async def free_function(value: int) -> int:
    return value


cached_free = alru_cache(free_function)


class Host:
    cached = cached_free

    def __init__(self, bias: int) -> None:
        self.bias = bias

    @alru_cache
    async def method(self, value: int) -> int:
        return value + self.bias


host = Host(2)

assert_type(
    Host.cached,
    Union[
        _LRUCacheWrapper[int],
        _LRUCacheWrapperInstanceMethod[int, Optional[Host]],
    ],
)
assert_type(
    host.cached,
    Union[_LRUCacheWrapper[int], _LRUCacheWrapperInstanceMethod[int, Host]],
)

wrapper_from_get = cached_free.__get__(None, Host)
assert_type(
    wrapper_from_get,
    Union[
        _LRUCacheWrapper[int],
        _LRUCacheWrapperInstanceMethod[int, Optional[Host]],
    ],
)
bound_from_get = cached_free.__get__(host, Host)
assert_type(
    bound_from_get,
    Union[_LRUCacheWrapper[int], _LRUCacheWrapperInstanceMethod[int, Host]],
)

assert_type(
    Host.method,
    Union[
        _LRUCacheWrapper[int],
        _LRUCacheWrapperInstanceMethod[int, Optional[Host]],
    ],
)
assert_type(
    host.method,
    Union[_LRUCacheWrapper[int], _LRUCacheWrapperInstanceMethod[int, Host]],
)


async def _check_call_results() -> None:
    host_cached_result = await host.cached(3)
    assert_type(host_cached_result, int)

    bound_get_result = await bound_from_get(4)
    assert_type(bound_get_result, int)

    host_method_result = await host.method(5)
    assert_type(host_method_result, int)
