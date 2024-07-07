package main

import (
  "fmt"
)

type pair struct {
  x int
  y int
}

func numberOfSubmatrices(grid [][]byte) int {
  m, n := len(grid), len(grid[0])
  dp := make([][]pair, m + 1)
  for i := 0; i <= m; i++ {
    dp[i] = make([]pair, n + 1)
  }
  ans := 0
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      x := dp[i + 1][j].x + dp[i][j + 1].x - dp[i][j].x
      y := dp[i + 1][j].y + dp[i][j + 1].y - dp[i][j].y
      if grid[i][j] == 'X' {
        x++
      } else if grid[i][j] == 'Y' {
        y++
      }
      dp[i + 1][j + 1].x = x
      dp[i + 1][j + 1].y = y
      if x == y && x > 0 {
        ans++
      }
    }
  }
  return ans
}

func main() {
  grid := [][]byte{
    {'x', 'Y', '.'},
    {'Y', '.', '.'},
  }
  fmt.Println(numberOfSubmatrices(grid))
}
