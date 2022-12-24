# WA
class Solution:
    def countAnagrams(self, s: str) -> int:
        n = len(s)
        ind = 0
        ans = 1
        MOD = 1e9 + 7

        def factorial(x):
            ret = 1
            for i in range(1, x + 1):
                ret *= i
            return ret

        def calc(word):
            cnts = [0 for i in range(26)]
            for c in word:
                cnts[ord(c) - ord('a')] += 1
            ret = 1
            ret *= factorial(len(word))
            for x in cnts:
                ret /= factorial(x)
            return ret
                
        while (ind < n):
            word = ""
            while (ind < n and s[ind] != ' '):
                word += s[ind]
                ind += 1
            if (ind < n):
                ind += 1
            ans = ans * calc(word) % MOD
        return int(ans)