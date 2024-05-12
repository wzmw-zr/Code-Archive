package main

import (
  "fmt"
  "math"
)


func maxScore(grid [][]int) int {
  m, n := len(grid), len(grid[0])
  ans := math.MinInt
  for i, mmin := 1, grid[0][0]; i < n; i++ {
    ans = max(ans, grid[0][i] - mmin)
    mmin = min(mmin, grid[0][i])
    grid[0][i] = mmin
  }
  for i, mmin := 1, grid[0][0]; i < m; i++ {
    ans = max(ans, grid[i][0] - mmin)
    mmin = min(mmin, grid[i][0])
    grid[i][0] = mmin
  }
  for i := 1; i < m; i++ {
    for j := 1; j < n; j++ {
      mmin := min(grid[i][0], grid[0][j])
      ans = max(ans, grid[i][j] - mmin)
      mmin = min(mmin, grid[i][j])
      grid[i][0] = mmin
      grid[0][j] = mmin
    }
  }
  return ans
}

func main() {
  grid := [][]int{
    {4, 3, 2},
    {3, 2, 1},
    // {9, 5, 7, 3},
    // {8, 9, 6, -1},
    // {6, 7, 14, 3},
    // {2, 5, 3, 1},
  }
  fmt.Println(maxScore(grid))
}
