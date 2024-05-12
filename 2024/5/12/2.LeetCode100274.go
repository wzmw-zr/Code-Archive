package main

import (
  "fmt"
  "math"
)

func maximumEnergy(energy []int, k int) int {
  n := len(energy)
  ans := math.MinInt
  for i := n - 1; i >= max(0, n - k); i-- {
    var sum int
    for j := i; j >= 0; j -= k {
      sum += energy[j]
      ans = max(ans, sum)
    }
  }
  return ans
}

func main() {
  energy := []int{5, 2, -10, -5, 1}
  k := 3
  fmt.Println(maximumEnergy(energy, k))
}
