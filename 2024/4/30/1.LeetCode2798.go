package main

import (
  "fmt"
)

func numberOfEmployeesWhoMetTarget(hours []int, target int) int {
  var ans int
  for _, h := range(hours) {
    if h >= target {
      ans++
    }
  }
  return ans
}
