import asyncio
import importlib
import importlib.machinery
import importlib.util
import sys
from pathlib import Path
from typing import Any, Callable

import async_lru
import pytest

REPO_ROOT = Path(__file__).resolve().parent


def _load_compiled_module(module_name: str) -> Any:
    for suffix in importlib.machinery.EXTENSION_SUFFIXES:
        candidate = REPO_ROOT / f"{module_name}{suffix}"
        if not candidate.exists():
            continue
        spec = importlib.util.spec_from_file_location(module_name, candidate)
        if spec is None or spec.loader is None:
            continue
        module = importlib.util.module_from_spec(spec)
        previous = sys.modules.get(module_name)
        sys.modules[module_name] = module
        try:
            spec.loader.exec_module(module)
        except Exception:
            if previous is None:
                sys.modules.pop(module_name, None)
            else:
                sys.modules[module_name] = previous
            raise
        return module

    module = importlib.import_module(module_name)
    origin = getattr(getattr(module, "__spec__", None), "origin", None)
    if origin is None or not origin.endswith(tuple(importlib.machinery.EXTENSION_SUFFIXES)):
        raise AssertionError(
            "Expected faster_async_lru to be loaded from a compiled extension module, "
            f"got {origin!r}."
        )
    return module


faster_async_lru = _load_compiled_module("faster_async_lru")


try:
    from pytest_codspeed import BenchmarkFixture
except ImportError:  # pragma: no branch  # only hit in cibuildwheel
    pytestmark = pytest.mark.skip("pytest-codspeed needs to be installed")
else:
    pytestmark = pytest.mark.benchmark


@pytest.fixture
def loop():
    # Save current loop to restore after the test
    try:
        old_loop = asyncio.get_running_loop()
    except RuntimeError:
        old_loop = None
    new_loop = asyncio.new_event_loop()
    asyncio.set_event_loop(new_loop)
    yield new_loop
    new_loop.close()
    if old_loop is not None:
        asyncio.set_event_loop(old_loop)


@pytest.fixture
def run_loop(loop):
    async def _get_coro(awaitable):
        """A helper function that turns an awaitable into a coroutine."""
        return await awaitable

    def run_the_loop(fn, *args, **kwargs):
        awaitable = fn(*args, **kwargs)
        coro = awaitable if asyncio.iscoroutine(awaitable) else _get_coro(awaitable)
        return loop.run_until_complete(coro)

    return run_the_loop


# Bounded cache (LRU)
async def _cached_func(x):
    return x


def create_cached_func():
    return async_lru.alru_cache(maxsize=128)(_cached_func)


def create_faster_cached_func():
    return faster_async_lru.alru_cache(maxsize=128)(_cached_func)


async def _cached_func_ttl(x):
    return x


def create_cached_func_ttl():
    return async_lru.alru_cache(maxsize=16, ttl=0.01)(_cached_func_ttl)


def create_faster_cached_func_ttl():
    return faster_async_lru.alru_cache(maxsize=16, ttl=0.01)(_cached_func_ttl)


# Unbounded cache (no maxsize)
async def _cached_func_unbounded(x):
    return x


def create_cached_func_unbounded():
    return async_lru.alru_cache()(_cached_func_unbounded)


def create_faster_cached_func_unbounded():
    return faster_async_lru.alru_cache()(_cached_func_unbounded)


async def _cached_func_unbounded_ttl(x):
    return x


def create_cached_func_unbounded_ttl():
    return async_lru.alru_cache(ttl=0.01)(_cached_func_unbounded_ttl)


def create_faster_cached_func_unbounded_ttl():
    return faster_async_lru.alru_cache(ttl=0.01)(_cached_func_unbounded_ttl)


def create_cached_meth():
    class MethodsInstance:
        @async_lru.alru_cache(maxsize=128)
        async def cached_meth(self, x):
            return x

    return MethodsInstance().cached_meth


def create_faster_cached_meth():
    class MethodsInstance:
        @faster_async_lru.alru_cache(maxsize=128)
        async def cached_meth(self, x):
            return x

    return MethodsInstance().cached_meth


def create_cached_meth_ttl():
    class MethodsInstance:
        @async_lru.alru_cache(maxsize=16, ttl=0.01)
        async def cached_meth_ttl(self, x):
            return x

    return MethodsInstance().cached_meth_ttl


def create_faster_cached_meth_ttl():
    class MethodsInstance:
        @faster_async_lru.alru_cache(maxsize=16, ttl=0.01)
        async def cached_meth_ttl(self, x):
            return x

    return MethodsInstance().cached_meth_ttl


def create_cached_meth_unbounded():
    class MethodsInstance:
        @async_lru.alru_cache()
        async def cached_meth_unbounded(self, x):
            return x

    return MethodsInstance().cached_meth_unbounded


def create_faster_cached_meth_unbounded():
    class MethodsInstance:
        @faster_async_lru.alru_cache()
        async def cached_meth_unbounded(self, x):
            return x

    return MethodsInstance().cached_meth_unbounded


def create_cached_meth_unbounded_ttl():
    class MethodsInstance:
        @async_lru.alru_cache(ttl=0.01)
        async def cached_meth_unbounded_ttl(self, x):
            return x

    return MethodsInstance().cached_meth_unbounded_ttl


def create_faster_cached_meth_unbounded_ttl():
    class MethodsInstance:
        @faster_async_lru.alru_cache(ttl=0.01)
        async def cached_meth_unbounded_ttl(self, x):
            return x

    return MethodsInstance().cached_meth_unbounded_ttl


async def uncached_func(x):
    return x


ids = ["bounded", "unbounded", "meth-bounded", "meth-unbounded"]
funcs = [
    create_cached_func,
    create_cached_func_unbounded,
    create_cached_meth,
    create_cached_meth_unbounded,
]
faster_funcs = [
    create_faster_cached_func,
    create_faster_cached_func_unbounded,
    create_faster_cached_meth,
    create_faster_cached_meth_unbounded,
]
funcs_ttl = [
    create_cached_func_ttl,
    create_cached_func_unbounded_ttl,
    create_cached_meth_ttl,
    create_cached_meth_unbounded_ttl,
]
faster_funcs_ttl = [
    create_faster_cached_func_ttl,
    create_faster_cached_func_unbounded_ttl,
    create_faster_cached_meth_ttl,
    create_faster_cached_meth_unbounded_ttl,
]


@pytest.mark.parametrize("factory", funcs, ids=ids)
def test_cache_hit_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(10))
    for key in keys:
        run_loop(func, key)

    async def run() -> None:
        for _ in range(100):
            for key in keys:
                await func(key)

    benchmark(run_loop, run)


@pytest.mark.parametrize("factory", faster_funcs, ids=ids)
def test_faster_cache_hit_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(10))
    for key in keys:
        run_loop(func, key)

    async def run() -> None:
        for _ in range(100):
            for key in keys:
                await func(key)

    benchmark(run_loop, run)


@pytest.mark.parametrize("factory", funcs, ids=ids)
def test_cache_miss_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    unique_objects = [object() for _ in range(128)]
    func.cache_clear()

    async def run() -> None:
        for obj in unique_objects:
            await func(obj)

    benchmark(run_loop, run)


@pytest.mark.parametrize("factory", faster_funcs, ids=ids)
def test_faster_cache_miss_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    unique_objects = [object() for _ in range(128)]
    func.cache_clear()

    async def run() -> None:
        for obj in unique_objects:
            await func(obj)

    benchmark(run_loop, run)


@pytest.mark.parametrize("factory", funcs, ids=ids)
def test_cache_clear_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    for i in range(100):
        run_loop(func, i)

    benchmark(func.cache_clear)


@pytest.mark.parametrize("factory", faster_funcs, ids=ids)
def test_faster_cache_clear_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    for i in range(100):
        run_loop(func, i)

    benchmark(func.cache_clear)


@pytest.mark.parametrize("factory", funcs_ttl, ids=ids)
def test_cache_ttl_expiry_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func_ttl = factory()
    run_loop(func_ttl, 99)
    run_loop(asyncio.sleep, 0.02)

    benchmark(run_loop, func_ttl, 99)


@pytest.mark.parametrize("factory", faster_funcs_ttl, ids=ids)
def test_faster_cache_ttl_expiry_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func_ttl = factory()
    run_loop(func_ttl, 99)
    run_loop(asyncio.sleep, 0.02)

    benchmark(run_loop, func_ttl, 99)


@pytest.mark.parametrize("factory", funcs, ids=ids)
def test_cache_invalidate_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(123, 321))
    for i in keys:
        run_loop(func, i)

    invalidate = func.cache_invalidate

    @benchmark
    def run() -> None:
        for i in keys:
            invalidate(i)


@pytest.mark.parametrize("factory", faster_funcs, ids=ids)
def test_faster_cache_invalidate_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(123, 321))
    for i in keys:
        run_loop(func, i)

    invalidate = func.cache_invalidate

    @benchmark
    def run() -> None:
        for i in keys:
            invalidate(i)


@pytest.mark.parametrize("factory", funcs, ids=ids)
def test_cache_info_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(1000))
    for i in keys:
        run_loop(func, i)

    cache_info = func.cache_info

    @benchmark
    def run() -> None:
        for _ in keys:
            cache_info()


@pytest.mark.parametrize("factory", faster_funcs, ids=ids)
def test_faster_cache_info_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(1000))
    for i in keys:
        run_loop(func, i)

    cache_info = func.cache_info

    @benchmark
    def run() -> None:
        for _ in keys:
            cache_info()


@pytest.mark.parametrize("factory", funcs, ids=ids)
def test_concurrent_cache_hit_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(600, 700))
    for key in keys:
        run_loop(func, key)

    async def gather_coros():
        gather = asyncio.gather
        for _ in range(10):
            return await gather(*map(func, keys))

    benchmark(run_loop, gather_coros)


@pytest.mark.parametrize("factory", faster_funcs, ids=ids)
def test_faster_concurrent_cache_hit_benchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    func = factory()
    keys = list(range(600, 700))
    for key in keys:
        run_loop(func, key)

    async def gather_coros():
        gather = asyncio.gather
        for _ in range(10):
            return await gather(*map(func, keys))

    benchmark(run_loop, gather_coros)


def test_cache_fill_eviction_benchmark(
    benchmark: BenchmarkFixture, run_loop: Callable[..., Any]
) -> None:
    func = create_cached_func()
    for i in range(-128, 0):
        run_loop(func, i)

    keys = list(range(5000))

    async def fill():
        for k in keys:
            await func(k)

    benchmark(run_loop, fill)


def test_faster_cache_fill_eviction_benchmark(
    benchmark: BenchmarkFixture, run_loop: Callable[..., Any]
) -> None:
    func = create_faster_cached_func()
    for i in range(-128, 0):
        run_loop(func, i)

    keys = list(range(5000))

    async def fill():
        for k in keys:
            await func(k)

    benchmark(run_loop, fill)


# ===========================
# Internal Microbenchmarks
# ===========================
# These benchmarks directly exercise internal (sync) methods and data structures
# not covered by the async public API benchmarks above.

# The relevant internal methods do not exist on _LRUCacheWrapperInstanceMethod,
# so we can skip methods for this part of the benchmark suite.
only_funcs = funcs[:2]
only_faster_funcs = faster_funcs[:2]
func_ids = ids[:2]


@pytest.mark.parametrize("factory", only_funcs, ids=func_ids)
def test_internal_cache_hit_microbenchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
) -> None:
    """Directly benchmark _cache_hit (internal, sync) using parameterized funcs."""
    func = factory()
    cache_hit = func._cache_hit

    # Populate cache
    keys = list(range(128))
    for i in keys:
        run_loop(func, i)

    @benchmark
    def run() -> None:
        for i in keys:
            cache_hit(i)


@pytest.mark.parametrize("factory", only_faster_funcs, ids=func_ids)
def test_faster_internal_cache_hit_microbenchmark(
    benchmark: BenchmarkFixture,
    run_loop: Callable[..., Any],
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
) -> None:
    """Directly benchmark _cache_hit (internal, sync) using parameterized funcs."""
    func = factory()
    cache_hit = func._cache_hit

    # Populate cache
    keys = list(range(128))
    for i in keys:
        run_loop(func, i)

    @benchmark
    def run() -> None:
        for i in keys:
            cache_hit(i)


@pytest.mark.parametrize("factory", only_funcs, ids=func_ids)
def test_internal_cache_miss_microbenchmark(
    benchmark: BenchmarkFixture, factory: Callable[[], async_lru._LRUCacheWrapper[Any]]
) -> None:
    """Directly benchmark _cache_miss (internal, sync) using parameterized funcs."""
    func = factory()
    cache_miss = func._cache_miss

    @benchmark
    def run() -> None:
        for i in range(128):
            cache_miss(i)


@pytest.mark.parametrize("factory", only_faster_funcs, ids=func_ids)
def test_faster_internal_cache_miss_microbenchmark(
    benchmark: BenchmarkFixture, factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]]
) -> None:
    """Directly benchmark _cache_miss (internal, sync) using parameterized funcs."""
    func = factory()
    cache_miss = func._cache_miss

    @benchmark
    def run() -> None:
        for i in range(128):
            cache_miss(i)


@pytest.mark.parametrize("factory", only_funcs, ids=func_ids)
@pytest.mark.parametrize("task_state", ["finished", "cancelled", "exception"])
def test_internal_task_done_callback_microbenchmark(
    benchmark: BenchmarkFixture,
    loop: asyncio.BaseEventLoop,
    factory: Callable[[], async_lru._LRUCacheWrapper[Any]],
    task_state: str,
) -> None:
    """Directly benchmark _task_done_callback (internal, sync) using parameterized funcs and task states."""
    func = factory()

    # Create a dummy coroutine and task
    async def dummy_coro():
        if task_state == "exception":
            raise ValueError("test exception")
        return 123

    task = loop.create_task(dummy_coro())
    if task_state == "finished":
        loop.run_until_complete(task)
    elif task_state == "cancelled":
        task.cancel()
        try:
            loop.run_until_complete(task)
        except asyncio.CancelledError:
            pass
    elif task_state == "exception":
        try:
            loop.run_until_complete(task)
        except Exception:
            pass

    iterations = range(1000)
    callback = func._task_done_callback
    @benchmark
    def run() -> None:
        for key in iterations:
            callback(key, task)


@pytest.mark.parametrize("factory", only_faster_funcs, ids=func_ids)
@pytest.mark.parametrize("task_state", ["finished", "cancelled", "exception"])
def test_faster_internal_task_done_callback_microbenchmark(
    benchmark: BenchmarkFixture,
    loop: asyncio.BaseEventLoop,
    factory: Callable[[], faster_async_lru._LRUCacheWrapper[Any]],
    task_state: str,
) -> None:
    """Directly benchmark _task_done_callback (internal, sync) using parameterized funcs and task states."""
    func = factory()

    # Create a dummy coroutine and task
    async def dummy_coro():
        if task_state == "exception":
            raise ValueError("test exception")
        return 123

    task = loop.create_task(dummy_coro())
    if task_state == "finished":
        loop.run_until_complete(task)
    elif task_state == "cancelled":
        task.cancel()
        try:
            loop.run_until_complete(task)
        except asyncio.CancelledError:
            pass
    elif task_state == "exception":
        try:
            loop.run_until_complete(task)
        except Exception:
            pass

    iterations = range(1000)
    callback = func._task_done_callback
    @benchmark
    def run() -> None:
        for key in iterations:
            callback(key, task)
