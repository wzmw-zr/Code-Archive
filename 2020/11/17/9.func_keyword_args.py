#!/usr/bin/env python
# coding=utf-8

def test(*args, **kw):
    print(args, kw)

d = {"a" : 1, "b" : 2, "c" : 3}
test(1, 2, 3, 4, **d)
