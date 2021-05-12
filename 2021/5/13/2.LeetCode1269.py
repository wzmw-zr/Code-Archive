class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:

        @lru_cache(None)
        def dfs(ind: int, step: int) -> int:
            if ind == -1 or ind == arrLen or ind > step:
                return 0
            if ind <= 1 and step == 1:
                return 1
            return dfs(ind, step - 1) + dfs(ind - 1, step - 1) + dfs(ind + 1, step - 1)


        return dfs(0, steps) % (10 ** 9 + 7)
