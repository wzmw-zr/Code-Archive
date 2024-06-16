package main

import (
  "fmt"
)

func countOfPeaks(nums []int, queries [][]int) []int {
  n := len(nums)
  bit := BIT{}
  bit.Init(n)
  for i := 0; i < n; i++ {
    if isPeak(nums, i) {
      bit.Add(i + 1, 1)
    }
  }
  ans := make([]int, 0)
  for _, q := range queries {
    if q[0] == 1 {
      l, r := q[1], q[2]
      cnt := bit.Query(r + 1) - bit.Query(l)
      if isPeak(nums, l) {
        cnt--
      }
      if isPeak(nums, r) {
        cnt--
      }
      if isPeak(nums, l) && l == r {
        cnt++
      }
      ans = append(ans, cnt)
    } else {
      idx, val := q[1], q[2]
      if isPeak(nums, idx) {
        bit.Add(idx + 1, -1)
      }
      if idx > 0 && isPeak(nums, idx - 1) {
        bit.Add(idx, -1)
      }
      if idx < n - 1 && isPeak(nums, idx + 1) {
        bit.Add(idx + 2, -1)
      }
      nums[idx] = val
      if isPeak(nums, idx) {
        bit.Add(idx + 1, 1)
      }
      if idx > 0 && isPeak(nums, idx - 1) {
        bit.Add(idx, 1)
      }
      if idx < n - 1 && isPeak(nums, idx + 1) {
        bit.Add(idx + 2, 1)
      }
    }
  }
  return ans
}

func isPeak(nums []int, idx int) bool {
  n := len(nums)
  if idx == 0 || idx == n - 1 {
    return false
  }
  return (nums[idx] > nums[idx - 1]) && (nums[idx] > nums[idx + 1])
}


type BIT struct {
  n int
  vals []int
}

func (b *BIT) Init(n int) {
  b.n = n
  b.vals = make([]int, n + 10)
}

func (b *BIT) Add(idx int, val int) {
  for idx <= b.n {
    b.vals[idx] += val
    idx += lowbit(idx)
  }
}

func (b *BIT) Query(idx int) int {
  ans := 0
  for idx > 0 {
    ans += b.vals[idx]
    idx -= lowbit(idx)
  }
  return ans
}

func lowbit(val int) int {
  return val & (val * -1)
}

func (b *BIT) Print() {
  for i := 1; i <= b.n; i++ {
    fmt.Printf("%d ", b.Query(i) - b.Query(i - 1))
  }
  fmt.Printf("\n")
}

func main() {
  nums := []int{
    4, 1, 4, 2, 1, 5,
  }
  queries := [][]int{
    {2, 2, 4, },
    {1, 0, 2, },
    {1, 0, 4, },
  }
  fmt.Println(countOfPeaks(nums, queries))
}
