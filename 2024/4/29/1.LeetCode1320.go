package main

import (
  "fmt"
  "slices"
)

func diagonalSort(mat [][]int) [][]int {
  m, n := len(mat), len(mat[0])
  var ans [][]int = make([][]int, m)
  for i := 0; i < m; i++ {
    ans[i] = make([]int, n)
  }
  for i := 0; i < m; i++ {
    var arr []int = make([]int, min(m - i, n))
    for j := 0; j < min(m - i, n); j++ {
      arr[j] = mat[i + j][j]
    }
    slices.Sort(arr)
    for j := 0; j < min(m - i, n); j++ {
      ans[i + j][j] = arr[j]
    }
  }
  for i := 1; i < n; i++ {
    var arr[]int = make([]int, min(n - i, m))
    for j := 0; j < min(n - i, m); j++ {
      arr[j] = mat[j][i + j]
    }
    slices.Sort(arr)
    for j := 0; j < min(n - i, m); j++ {
      ans[j][i + j] = arr[j]
    }
  }
  return ans
}

func main() {
  var mat [][]int = [][]int{
    {3, 3, 1, 1},
    {2, 2, 1, 2},
    {1, 1, 1, 2},
  }
  fmt.Printf("%+v\n", mat)
  fmt.Printf("%+v\n", diagonalSort(mat))
}
