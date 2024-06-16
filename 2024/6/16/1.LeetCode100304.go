package main

import (
  "fmt"
)

func countCompleteDayPairs(hours []int) int {
  cnts := make([]int, 24)
  ans := 0
  for _, h := range hours {
    ans += cnts[(24 - (h % 24)) % 24]
    cnts[h % 24]++
  }
  return ans
}
