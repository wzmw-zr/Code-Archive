package main

import (
  "fmt"
  "strconv"
)

func max(x, y int) int {
  if x >= y {
    return x
  }
  return y
}

func findColumnWidth(grid [][]int) []int {
  var m, n int
  m, n = len(grid), len(grid[0])
  var ans []int = make([]int, n)
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      var w int = len(strconv.Itoa(grid[i][j]))
      ans[j] = max(ans[j], w)
    }
  }
  return ans
}

func main() {
  var grid [][]int = [][]int{{1}, {22}, {333}}
  fmt.Println(findColumnWidth(grid))
}
