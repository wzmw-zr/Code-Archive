package main

import (
  "fmt"
)

func decrypt(code []int, k int) []int {
  var n int = len(code)
  var ans []int = make([]int, n)
  var flag int
  if k > 0 {
    flag = 1
  } else {
    flag = -1
  }
  k *= flag
  var sum int
  for i := 1; i <= k; i++ {
    var idx int = (flag * i + n) % n
    sum += code[idx]
  }
  for i := 0; i < n; i++ {
    ans[i] = sum
    if flag > 0 {
      sum = sum - code[(i + 1) % n] + code[(i + k + 1) % n]
    } else {
      sum = sum - code[(i - k + n) % n] + code[i]
    }
  }
  return ans
}

func main() {
  var code []int = []int{2, 4, 9, 3}
  var k int = -2
  fmt.Println(decrypt(code, k))
}
