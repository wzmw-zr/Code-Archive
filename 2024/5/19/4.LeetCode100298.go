package main

import (
  "fmt"
  "math"
)

// WA
func waysToReachStair(k int) int {
  mp := make(map[string]int)
  var dfs func(int, int, int, int)int;
  dfs = func(pos int, jump int, preDown int, cntDown int)int{
    status := fmt.Sprintf("%d:%d:%d:%d", pos, jump, preDown, cntDown)
    if pos > k + 1 {
      return 0
    }
    if cnt, ok := mp[status]; ok {
      return cnt
    }
    ans := 0
    if pos == k {
      ans++
    }
    ans += dfs(pos + int(math.Pow(float64(2), float64(jump))), jump + 1, 0, cntDown)
    if preDown == 0 || pos != 0 {
      ans += dfs(pos - 1, jump, 1, cntDown + 1)
    }
    mp[status] = ans
    return ans
  }
  ans := dfs(1, 0, 0, 0)
  for k, v := range mp {
    fmt.Println(k, v)
  }
  return ans
}

func main() {
  k := 1
  fmt.Println(waysToReachStair(k))
}
