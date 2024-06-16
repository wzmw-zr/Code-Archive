package main

import (
  "fmt"
  "slices"
)

func maximumTotalDamage(power []int) int64 {
  slices.Sort(power)
  fmt.Println(power)
  mp := make(map[int]int64)
  preMax := make(map[int]int64)
  ans := int64(0)
  for _, p := range power {
    if _, ok := mp[p]; !ok {
      idx1 := findLastLe(power, p - 1)
      idx2 := findLastLe(power, p - 3)
      if power[idx1] <= p - 1 {
        preMax[p] = preMax[power[idx1]]
      } else {
        preMax[p] = 0
      }
      if power[idx2] <= p - 3 {
        mp[p] = preMax[power[idx2]]
      } else {
        mp[p] = 0
      }
    }
    mp[p] += int64(p)
    ans = max(ans, mp[p])
    preMax[p] = max(preMax[p], mp[p])
  }
  return ans
}

func findLastLe(power []int, val int) int {
  l, r := 0, len(power) - 1
  for l < r {
    mid := (l + r + 1) / 2
    if power[mid] <= val {
      l = mid
    } else {
      r = mid - 1
    }
  }
  return l
}

func main() {
  power := []int{
    5,9,2,10,2,7,10,9,3,8,
  }
  fmt.Println(maximumTotalDamage(power))
}
