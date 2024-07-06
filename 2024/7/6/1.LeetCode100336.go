package main

import (
  "fmt"
)

func numberOfAlternatingGroups(colors []int) int {
  n := len(colors)
  cnt := 0
  for i := 0; i < n; i++ {
    l := (i - 1 + n) % n
    r := (i + 1) % n
    if colors[i] != colors[l] && colors[i] != colors[r] {
      cnt++
    }
  }
  return cnt
}
