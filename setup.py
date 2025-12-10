from setuptools import setup
from mypyc.build import mypycify


setup(ext_modules=mypycify(["faster_async_lru", "--strict", "--pretty", "--disable-error-code=unused-ignore"], group_name="faster_async_lru"))
