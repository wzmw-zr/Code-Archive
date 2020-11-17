#!/usr/bin/env python
# coding=utf-8

def func(a: int=10, b: list=list(range(10)), c: dict=dict()):
    print(a, b, c)

func()
func(100)
func(100, list(range(10)), {x : x ** 2 for x in range(5)})
