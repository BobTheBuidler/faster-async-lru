"""Mypy-only checks for parameter shape permutations."""

from __future__ import annotations

from typing import Optional

from faster_async_lru import _LRUCacheWrapper, alru_cache

from typing_extensions import assert_type


@alru_cache
async def positional_only(x: int, /, y: int) -> int:
    return x + y


@alru_cache
async def keyword_only(*, x: int, y: int = 0) -> int:
    return x + y


@alru_cache
async def var_args(*values: int) -> int:
    return sum(values)


@alru_cache
async def var_kwargs(**values: int) -> int:
    return sum(values.values())


@alru_cache
async def mixed_args(x: int, /, y: int, *values: int, scale: int = 1) -> int:
    return (x + y + sum(values)) * scale


@alru_cache
async def optional_args(x: Optional[int] = None) -> Optional[int]:
    return x


@alru_cache
async def kw_only_optional(*, x: Optional[int], y: Optional[str] = None) -> int:
    return 0 if x is None else x


@alru_cache(maxsize=16, typed=True, ttl=None)
async def typed_factory(x: int, /, y: str, *, z: float = 0.0) -> str:
    return f"{x}{y}{z}"


assert_type(positional_only, _LRUCacheWrapper[int])
assert_type(keyword_only, _LRUCacheWrapper[int])
assert_type(var_args, _LRUCacheWrapper[int])
assert_type(var_kwargs, _LRUCacheWrapper[int])
assert_type(mixed_args, _LRUCacheWrapper[int])
assert_type(optional_args, _LRUCacheWrapper[Optional[int]])
assert_type(kw_only_optional, _LRUCacheWrapper[int])
assert_type(typed_factory, _LRUCacheWrapper[str])


async def _check_call_results() -> None:
    assert_type(await positional_only(1, 2), int)
    assert_type(await keyword_only(x=1, y=2), int)
    assert_type(await var_args(1, 2, 3), int)
    assert_type(await var_kwargs(a=1, b=2), int)
    assert_type(await mixed_args(1, 2, 3, 4, scale=2), int)
    assert_type(await optional_args(None), Optional[int])
    assert_type(await optional_args(5), Optional[int])
    assert_type(await kw_only_optional(x=None), int)
    assert_type(await kw_only_optional(x=1, y="a"), int)
    assert_type(await typed_factory(1, "x", z=1.5), str)
