package main

import (
  "fmt"
  "math"
  "slices"
  "strings"
)

func check(s string, k int) bool {
  var n int = len(s)
  var mp map[string]int = make(map[string]int)
  for i := 0; i < n; i += k {
    var chars []byte = []byte(strings.Clone(s[i: i + k]))
    slices.Sort(chars)
    mp[string(chars)]++
    if len(mp) > 1 {
      return false
    }
  }
  return true
}

func minAnagramLength(s string) int {
  var n int = len(s)
  var ans int = n
  var mid int = int(math.Sqrt(float64(n)))
  for i := 1; i <= mid; i++ {
    if n % i != 0 {
      continue
    }
    if check(s, i) {
      ans = min(ans, i)
    }
    if check(s, n / i) {
      ans = min(ans, n / i)
    }
  }
  return ans
}

func main() {
  var s string
  fmt.Scanf("%s", &s)
  fmt.Println(minAnagramLength(s))
}
