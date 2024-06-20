package main

import (
  "fmt"
)

func temperatureTrend(temperatureA []int, temperatureB []int) int {
  n := len(temperatureA)
  arrA := make([]int, n - 1)
  arrB := make([]int, n - 1)
  for i := 0; i < n - 1; i++ {
    diff := temperatureA[i + 1] - temperatureA[i]
    if diff > 0 {
      arrA[i] = 1
    } else if diff == 0 {
      arrA[i] = 0
    } else {
      arrA[i] = -1
    }
  }
  for i := 0; i < n - 1; i++ {
    diff := temperatureB[i + 1] - temperatureB[i]
    if diff > 0 {
      arrB[i] = 1
    } else if diff == 0 {
      arrB[i] = 0
    } else {
      arrB[i] = -1
    }
  }
  ans := 0
  for i, j := 0, 0; i < n - 1 && j < n - 1; {
    for j < n - 1 && arrA[j] == arrB[j] {
      j++
    }
    ans = max(ans, j - i)
    j++
    i = j
  }
  return ans
}

func main() {
  tA := []int{
    21, 18, 18, 18, 31,
  }
  tB := []int{
    34, 32, 16, 16, 17,
  }
  fmt.Println(temperatureTrend(tA, tB))
}
