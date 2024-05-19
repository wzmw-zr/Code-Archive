package main

import (
  "fmt"
)

func isArraySpecial(nums []int, queries [][]int) []bool {
  n := len(nums)
  q := len(queries)
  dp := make([]int, n)
  for i := 0; i < n; i++ {
    dp[i] = 1
  }
  for i := 1; i < n; i++ {
    if (nums[i - 1] % 2) + (nums[i] % 2) == 1 {
      dp[i] = dp[i - 1] + 1
    }
  }
  ans := make([]bool, q)
  for i, q := range queries {
    f, t := q[0], q[1]
    if t - f + 1 <= dp[t] {
      ans[i] = true
    }
  }
  return ans
}

func main() {
  nums := []int{3, 4, 1, 2, 6}
  queries := [][]int{
    {0, 4},
  }
  fmt.Println(isArraySpecial(nums, queries))
}
