#!/usr/bin/env python
# coding=utf-8

class Solution(object):
    def to_digit(self, n):
        s = ""
        temp = n
        while temp:
            s += str(temp & 1)
            temp >>= 1
        return s[-1:0:-1]

    def concatenatedBinary(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = ""
        for i in range(1, n + 1, 1):
            s = s + self.to_digit(i)
        print(s)
        return 1000000007

s = Solution()
print(s.concatenatedBinary(1))
