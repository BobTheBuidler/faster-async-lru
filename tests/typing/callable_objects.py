"""Mypy-only checks for callable objects and wrapper reuse edge cases."""

from __future__ import annotations

from typing import Generic, TypeVar

from faster_async_lru import _LRUCacheWrapper, alru_cache

from typing_extensions import assert_type


class AsyncCallable:
    async def __call__(self, value: int, /, *, label: str = "") -> str:
        return f"{value}{label}"


async_callable = AsyncCallable()
wrapped_callable = alru_cache(async_callable)

assert_type(wrapped_callable, _LRUCacheWrapper[str])


T = TypeVar("T")


class Box(Generic[T]):
    async def __call__(self, value: T) -> T:
        return value


boxed_int = Box[int]()
wrapped_boxed_int = alru_cache(boxed_int)

assert_type(wrapped_boxed_int, _LRUCacheWrapper[int])

wrapped_twice = alru_cache(wrapped_boxed_int)
assert_type(wrapped_twice, _LRUCacheWrapper[int])


async def _check_call_results() -> None:
    callable_result = await wrapped_callable(1, label="x")
    assert_type(callable_result, str)

    boxed_result = await wrapped_boxed_int(3)
    assert_type(boxed_result, int)

    wrapped_twice_result = await wrapped_twice(4)
    assert_type(wrapped_twice_result, int)
