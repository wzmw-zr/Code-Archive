#!/usr/bin/env python
# coding=utf-8
def func(a: int=1, b: list=list(range(100)), c: dict={}):
    print(a, b, c)

func()
func(10, range(1000), dict([[x, x ** 2] for x in range(100)]))
