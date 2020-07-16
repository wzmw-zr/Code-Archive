#!/usr/bin/env python
# coding=utf-8

"""
instance of random module
"""

import random

"""random.random() will return float between 0 and 1"""
print(random.random())

"""random.randint() will return random number in a area"""
"""
arguments format:
random.randint(left, right)
"""
print(random.randint(0, 100))

"""random.choice(): get a random item from list"""
print(random.choice([120, 110, 119]))
