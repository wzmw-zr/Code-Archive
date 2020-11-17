#!/usr/bin/env python
# coding=utf-8

def print_func_name(func):
    def new_func(*args, **kw):
        print(f"function {func.__name__}() will de called.")
        return func(*args, **kw)
    return new_func

@print_func_name
def show():
    print("Hello world!")

@print_func_name
def add(a: int, b: int) -> int:
    print(a + b)
    return a + b

show()
add(10, 11)
