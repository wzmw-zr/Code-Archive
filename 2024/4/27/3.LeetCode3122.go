package main

import "fmt"

const MAX = 0x3f3f3f3f

func min(x, y int) int {
  if x < y {
    return x
  }
  return y
}

func minimumOperations(grid [][]int) int {
  var m, n int = len(grid), len(grid[0])
  var cnts [][]int = make([][]int, n)
  for i := 0; i < n; i++ {
    cnts[i] = make([]int, 10)
  }
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      cnts[j][grid[i][j]]++
    }
  }
  var dp [][]int = make([][]int, n)
  for i := 0; i < n; i++ {
    dp[i] = make([]int, 10)
  }
  for i := 0; i < n; i++ {
    for j := 0; j <= 9; j++ {
      dp[i][j] = MAX
    }
  }
  for i := 0; i <= 9; i++ {
    dp[0][i] = m - cnts[0][i]
  }
  for i := 1; i < n; i++ {
    for j := 0; j <= 9; j++ {
      var min_ops int = MAX
      for k := 0; k <= 9; k++ {
        if k == j {
          continue
        }
        min_ops = min(min_ops, dp[i - 1][k])
      }
      dp[i][j] = min_ops + m - cnts[i][j]
    }
  }
  var ans int = MAX
  for i := 0; i <= 9; i++ {
    ans = min(ans, dp[n - 1][i])
  }
  return ans
}

func main() {
  var grid [][]int = [][]int{
    {1, }, {2, }, {3, },
    // {1, 1, 1, },
    // {0, 0, 0, },
  }
  fmt.Println(minimumOperations(grid))
}
