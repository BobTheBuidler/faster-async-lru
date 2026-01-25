"""Mypy-only negative checks for invalid alru_cache usage."""

from __future__ import annotations

from faster_async_lru import alru_cache


def sync_func(value: int) -> int:
    return value


alru_cache(sync_func)  # type: ignore[arg-type]

alru_cache("not a callable")  # type: ignore[call-overload]

alru_cache(3.14)  # type: ignore[call-overload]

alru_cache(maxsize="invalid")  # type: ignore[call-overload]

alru_cache(maxsize=1.5)  # type: ignore[call-overload]

alru_cache(ttl="invalid")  # type: ignore[call-overload]

alru_cache(typed="invalid")  # type: ignore[call-overload]


@alru_cache
async def accepts_hashable(value: int) -> int:
    return value


accepts_hashable.cache_invalidate(["unhashable"])  # type: ignore[arg-type]
