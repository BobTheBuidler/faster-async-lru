from mypyc.build import mypycify
from setuptools import setup

setup(
    ext_modules=mypycify(
        [
            "faster_async_lru/__init__.py",
            "--strict",
            "--pretty",
            "--disable-error-code=unused-ignore",
        ]
    )
)
