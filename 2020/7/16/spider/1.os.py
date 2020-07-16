#!/usr/bin/env python
# coding=utf-8

import os
import sys

# open file
path = "/home/zr/"

dirs = os.listdir(path)

for file in dirs:
    print(file)

# create multi-level directory
path = "./test/git/a/b/c/e"
if os.path.exists(path):
    print(f"{path} exists")
else:
    os.makedirs(path)
    print("make directory successful!")
# judge path exists or not
