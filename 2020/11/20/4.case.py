#!/usr/bin/env python
# coding=utf-8

def dfs(str_list: list, ind: int, string: str, target: str) -> int:
    if ind == len(str_list):
        return 0
    if len(string) > len(target):
        return 0
    if string not in target:
        return 0
    if string == target:
        return 1
    cnt = 0
    for i in range(ind, len(str_list)):
        cnt += dfs(str_list, i + 1, string + str_list[i], target)
    return cnt
