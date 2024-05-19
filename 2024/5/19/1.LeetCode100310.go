package main

import (
  "fmt"
)

func isArraySpecial(nums []int) bool {
  n := len(nums)
  for i := 0; i < n - 1; i++ {
    if (nums[i] % 2) + (nums[i + 1] % 2) == 1 {
      continue
    }
    return false
  }
  return true
}

func main() {
  nums := []int{4, 3, 1, 6}
  fmt.Println(isArraySpecial(nums))
}
