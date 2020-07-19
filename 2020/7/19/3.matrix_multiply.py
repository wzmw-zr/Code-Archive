#!/usr/bin/env python
# coding=utf-8
import numpy as np

a = [
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1]
]


b = [
    [1, 2, 3],
    [5, 6, 7]
]

print(np.dot(b, a))

a = np.mat(a)

print(a.I)
