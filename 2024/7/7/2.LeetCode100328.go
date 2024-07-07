package main

import (
  "fmt"
)

func validStrings(n int) []string {
  ans := make([]string, 0)
  var dfs func(s []byte)
  dfs = func(s []byte) {
    if len(s) == n {
      ans = append(ans, string(s))
      return
    }
    if len(s) > 0 && s[len(s) - 1] == '0' {
      s = append(s, '1')
      dfs(s)
    } else {
      s = append(s, '0')
      dfs(s)
      s = s[:len(s) - 1]
      s = append(s, '1')
      dfs(s)
    }
  }
  arr := make([]byte, 0, n)
  dfs(arr)
  return ans
}

func main() {
  n := 18
  fmt.Println(validStrings(n))
}
