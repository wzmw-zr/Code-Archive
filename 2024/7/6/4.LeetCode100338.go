package main

import (
  "fmt"
)

func countSubarrays(nums []int, k int) int64 {
  ans := int64(0)
  mp := make(map[int]int64)
  if nums[0] == k {
    ans++
  }
  mp[nums[0]] = 1
  for i := 1; i < len(nums); i++ {
    tmp := make(map[int]int64)
    tmp[nums[i]] = 1
    for key, cnt := range mp {
      if (key & nums[i] & k) < k {
        continue
      }
      x := key & nums[i]
      if _, ok := tmp[x]; !ok {
        tmp[x] = cnt
      } else {
        tmp[x] += cnt
      }
    }
    if cnt, ok := tmp[k]; ok {
      ans += cnt
    }
    mp = tmp
  }
  return ans
}

func main() {
  nums := []int{
    1, 1, 1,
  }
  k := 1
  fmt.Println(countSubarrays(nums, k))
}
