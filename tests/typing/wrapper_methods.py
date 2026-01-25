"""Mypy-only checks for wrapper methods and descriptor behavior."""

from __future__ import annotations

from collections.abc import Awaitable, Callable
from typing import Optional, Union

from faster_async_lru import (
    _CacheInfo,
    _CacheParameters,
    _LRUCacheWrapper,
    _LRUCacheWrapperInstanceMethod,
    alru_cache,
)

from typing_extensions import assert_type


@alru_cache
async def fetch(value: int, *, label: str = "") -> str:
    return f"{value}{label}"


assert_type(fetch, _LRUCacheWrapper[str])
fetch_cache_clear: Callable[[], None] = fetch.cache_clear
fetch_cache_close: Callable[..., Awaitable[None]] = fetch.cache_close

fetch_invalidate = fetch.cache_invalidate(1, label="x")
assert_type(fetch_invalidate, bool)
fetch_info = fetch.cache_info()
assert_type(fetch_info, _CacheInfo)
fetch_parameters = fetch.cache_parameters()
assert_type(fetch_parameters, _CacheParameters)
assert_type(fetch_parameters["typed"], bool)
assert_type(fetch_parameters["maxsize"], Optional[int])
assert_type(fetch_parameters["tasks"], int)
assert_type(fetch_parameters["closed"], bool)


class Service:
    @alru_cache
    async def compute(self, value: int, *, scale: float = 1.0) -> float:
        return value * scale


service = Service()

assert_type(
    Service.compute,
    Union[
        _LRUCacheWrapper[float],
        _LRUCacheWrapperInstanceMethod[float, Optional[Service]],
    ],
)
assert_type(
    service.compute,
    Union[_LRUCacheWrapper[float], _LRUCacheWrapperInstanceMethod[float, Service]],
)
service_cache_clear: Callable[[], None] = service.compute.cache_clear
service_cache_close: Callable[..., Awaitable[None]] = service.compute.cache_close

service_invalidate = service.compute.cache_invalidate(3, scale=2.0)
assert_type(service_invalidate, bool)
service_info = service.compute.cache_info()
assert_type(service_info, _CacheInfo)
service_parameters = service.compute.cache_parameters()
assert_type(service_parameters, _CacheParameters)
assert_type(service_parameters["typed"], bool)
assert_type(service_parameters["maxsize"], Optional[int])
assert_type(service_parameters["tasks"], int)
assert_type(service_parameters["closed"], bool)


async def _check_call_results() -> None:
    fetch_result = await fetch(1, label="x")
    assert_type(fetch_result, str)

    await fetch.cache_close()

    service_result = await service.compute(3, scale=2.0)
    assert_type(service_result, float)

    await service.compute.cache_close()
