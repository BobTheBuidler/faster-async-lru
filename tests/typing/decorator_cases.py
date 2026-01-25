"""Mypy-only checks for alru_cache decorator overloads and call signatures."""

from __future__ import annotations

from typing import NewType, Optional, Union

from faster_async_lru import _LRUCacheWrapper, alru_cache

from typing_extensions import Annotated, Literal, assert_type


class Widget:
    def __init__(self, name: str) -> None:
        self.name = name


UserId = NewType("UserId", int)


@alru_cache
async def direct_int(value: int, /, label: str = "") -> int:
    return value


@alru_cache
async def direct_str(value: str) -> str:
    return value


@alru_cache
async def direct_none(flag: bool) -> None:
    if flag:
        return None
    return None


@alru_cache
async def direct_union(value: Union[int, str]) -> Union[int, str]:
    return value


@alru_cache
async def direct_optional_union(
    value: Optional[Union[int, str]],
) -> Optional[Union[int, str]]:
    return value


@alru_cache
async def direct_optional(value: Optional[Widget]) -> Optional[Widget]:
    return value


@alru_cache
async def direct_custom(value: str) -> Widget:
    return Widget(value)


@alru_cache
async def direct_list(value: str) -> list[Widget]:
    return [Widget(value)]


@alru_cache
async def direct_literal(flag: bool) -> Literal["ok"]:
    if flag:
        return "ok"
    return "ok"


@alru_cache
async def direct_newtype(value: UserId) -> UserId:
    return value


@alru_cache
async def direct_tuple(value: int, label: str) -> tuple[int, str]:
    return value, label


@alru_cache
async def direct_dict(value: str) -> dict[str, Widget]:
    return {value: Widget(value)}


@alru_cache
async def direct_annotated(value: Annotated[int, "id"]) -> Annotated[int, "id"]:
    return value


@alru_cache(maxsize=0, typed=True, ttl=0.1)
async def factory_positional_only(value: int, /, suffix: str) -> str:
    return f"{value}{suffix}"


@alru_cache(maxsize=1, typed=False, ttl=None)
async def factory_keyword_only(*, value: int, suffix: str = "") -> str:
    return f"{value}{suffix}"


@alru_cache(maxsize=128, typed=False, ttl=None)
async def factory_defaulted(value: int, label: str = "x") -> int:
    return value


@alru_cache(maxsize=64, typed=True, ttl=None)
async def factory_mixed(value: int, /, *extra: int, label: str) -> int:
    return value + len(extra) + len(label)


@alru_cache(maxsize=None, typed=True)
async def factory_var_args(*values: int, **labels: str) -> int:
    return len(values) + len(labels)


@alru_cache()
async def factory_defaults(value: int, label: str = "default") -> str:
    return f"{value}{label}"


@alru_cache(maxsize=None, typed=False, ttl=0.0)
async def factory_ttl_zero(value: int) -> int:
    return value


wrapped_from_callable = alru_cache(direct_int)
wrapped_no_args = alru_cache()(direct_str)
assert_type(wrapped_from_callable, _LRUCacheWrapper[int])
assert_type(wrapped_no_args, _LRUCacheWrapper[str])
assert_type(direct_int, _LRUCacheWrapper[int])
assert_type(direct_none, _LRUCacheWrapper[None])
cache_invalidate_result = direct_int.cache_invalidate(1, label="x")
assert_type(cache_invalidate_result, bool)


async def plain_callable(value: float) -> float:
    return value


wrapped_plain = alru_cache(plain_callable)
assert_type(wrapped_plain, _LRUCacheWrapper[float])
double_wrapped = alru_cache(wrapped_plain)
assert_type(double_wrapped, _LRUCacheWrapper[float])


async def _check_call_results() -> None:
    direct_int_value = await direct_int(1)
    assert_type(direct_int_value, int)

    wrapped_result = await wrapped_from_callable(1)
    assert_type(wrapped_result, int)

    direct_int_result = await direct_int(1, "a")
    assert_type(direct_int_result, int)

    direct_str_result = await direct_str("value")
    assert_type(direct_str_result, str)

    await direct_none(True)

    direct_union_int_result = await direct_union(1)
    assert_type(direct_union_int_result, Union[int, str])

    direct_union_str_result = await direct_union("x")
    assert_type(direct_union_str_result, Union[int, str])

    direct_optional_union_result = await direct_optional_union(None)
    assert_type(direct_optional_union_result, Optional[Union[int, str]])

    direct_optional_result = await direct_optional(None)
    assert_type(direct_optional_result, Optional[Widget])

    direct_custom_result = await direct_custom("name")
    assert_type(direct_custom_result, Widget)

    direct_list_result = await direct_list("name")
    assert_type(direct_list_result, list[Widget])

    direct_literal_result = await direct_literal(True)
    assert_type(direct_literal_result, Literal["ok"])

    direct_newtype_result = await direct_newtype(UserId(5))
    assert_type(direct_newtype_result, UserId)

    direct_tuple_result = await direct_tuple(1, "a")
    assert_type(direct_tuple_result, tuple[int, str])

    direct_dict_result = await direct_dict("key")
    assert_type(direct_dict_result, dict[str, Widget])

    direct_annotated_result = await direct_annotated(3)
    assert_type(direct_annotated_result, Annotated[int, "id"])

    factory_positional_result = await factory_positional_only(3, "s")
    assert_type(factory_positional_result, str)

    factory_keyword_result = await factory_keyword_only(value=3)
    assert_type(factory_keyword_result, str)

    factory_defaulted_result = await factory_defaulted(3)
    assert_type(factory_defaulted_result, int)

    factory_mixed_result = await factory_mixed(3, 4, 5, label="zz")
    assert_type(factory_mixed_result, int)

    factory_varargs_result = await factory_var_args(1, 2, 3, label="x")
    assert_type(factory_varargs_result, int)

    factory_defaults_result = await factory_defaults(2)
    assert_type(factory_defaults_result, str)

    factory_ttl_result = await factory_ttl_zero(5)
    assert_type(factory_ttl_result, int)

    wrapped_no_args_result = await wrapped_no_args("value")
    assert_type(wrapped_no_args_result, str)

    wrapped_plain_result = await wrapped_plain(2.5)
    assert_type(wrapped_plain_result, float)
