package main

import (
  "fmt"
)

func sumDigitDifferences(nums []int) int64 {
  n := int64(len(nums))
  ans := int64(0)
  cnts := make([][]int64, 10)
  for i := 0; i < 10; i++ {
    cnts[i] = make([]int64, 10)
  }
  for _, x := range nums {
    for i := 0; i < 10; i++ {
      cnts[i][x % 10]++
      x /= 10
    }
  }
  for i := 0; i < 10; i++ {
    for j := 0; j < 10; j++ {
      ans += cnts[i][j] * (n - cnts[i][j])
    }
  }
  return ans / 2
}

func main() {
  nums := []int{10, 10, 10, 10}
  fmt.Println(sumDigitDifferences(nums))
}
