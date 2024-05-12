package main

import (
  "fmt"
)


func findPermutationDifference(s string, t string) int {
  var ans int
  var pos_s []int = make([]int, 26)
  var pos_t []int = make([]int, 26)
  for idx, ch := range s {
    pos_s[ch - 'a'] = idx
  }
  for idx, ch := range t {
    pos_t[ch - 'a'] = idx
  }
  for i := 0; i < 26; i++ {
    ans += abs(pos_s[i] - pos_t[i])
  }
  return ans
}

func abs(x int) int {
  if x >= 0 {
    return x
  }
  return x * -1
}
