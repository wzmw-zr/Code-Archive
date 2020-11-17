#!/usr/bin/env python
# coding=utf-8

a = list(range(10))
print(id(a), a)

def show():
    a = list(range(3))
    print(id(a), a)

def update(arr: list):
    arr *= 3
    print(id(arr), arr)

show()
update(a)
print(id(a), a)

b = 1
print(id(b), b)
def print_num():
    print(b)
print_num()
def change(num: int):
    print(id(num), num)
    num += 10
    print(id(num), num)
change(b)
print(id(b), b)
