#!/usr/bin/env python
# coding=utf-8

import numpy as np

a = [
    [3, 2, 1],
    [1, 2, 3]
]

a = np.matrix(a)

print(np.dot(a, np.transpose(a)))
