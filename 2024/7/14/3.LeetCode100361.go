package main

import (
  "fmt"
)

func minimumCost(m int, n int, horizontalCut []int, verticalCut []int) int {
  dp := make([][]int, m + 1)
  for i := 0; i <= m; i++ {
    dp[i] = make([]int, n + 1)
  }
  horizontalCut = append([]int{0}, horizontalCut...)
  verticalCut = append([]int{0}, verticalCut...)
  pre_h := make([]int, m + 1)
  pre_v := make([]int, n + 1)
  for i := 1; i <= m; i++ {
    pre_h[i] = pre_h[i - 1] + horizontalCut[i - 1]
  }
  for i := 1; i <= n; i++ {
    pre_v[i] = pre_v[i - 1] + verticalCut[i - 1]
  }
  for i := 1; i <= m; i++ {
    for j := 1; j <= n; j++ {
      dp[i][j] = min(
        dp[i][j - 1] + min(pre_h[i - 1], i * verticalCut[j - 1]),
        dp[i - 1][j] + min(pre_v[j - 1], j * horizontalCut[i - 1]),
      )
    }
  }
  return dp[m][n]
}
