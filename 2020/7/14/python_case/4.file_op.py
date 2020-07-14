#!/usr/bin/env python
# coding=utf-8

"""
fd = open("file_case.txt", "a+", encoding="utf-8")
fd.write("hello")
fd.close()
"""

fd = open("./4.file_op.py", "r", encoding="utf-8")

lines = fd.readlines()
print(lines)

fd.close()
