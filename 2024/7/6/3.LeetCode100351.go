package main

import (
  "fmt"
)

func numberOfAlternatingGroups(colors []int, k int) int {
  colors = append(colors, colors...)
  check := make([]int, len(colors))
  l, r := 0, 1
  ans := 0
  for l < len(colors) / 2 && r < len(colors) {
    for r < len(colors) && colors[r] != colors[r - 1] {
      r++
    }
    for i := l; i <= r - k; i++ {
      check[i] = 1
    }
    l = r
    r++
  }
  for i := 0; i < len(colors) / 2; i++ {
    ans += check[i]
  }
  return ans
}

func main() {
  colors := []int{
    0, 1, 0, 0, 1, 0, 1,
  }
  k := 6
  fmt.Println(numberOfAlternatingGroups(colors, k))
}
