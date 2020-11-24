#!/usr/bin/env python
# coding=utf-8
import json

a = [x for x in range(100)]
b = {x : x ** 2 for x in range(100)}

c = json.dumps(a)
print(c)

d = json.dumps(b)
print(b)

print(json.loads(c))
print(json.loads(d))
