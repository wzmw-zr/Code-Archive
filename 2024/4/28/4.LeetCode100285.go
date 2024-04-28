package main

import (
  "fmt"
  "sort"
)

type IntSlice []int

func (n IntSlice) Len() int {
  return len(n)
}

func (n IntSlice) Less(i, j int) bool {
  return n[i] < n[j]
}

func (n IntSlice) Swap(i, j int) {
  n[i], n[j] = n[j], n[i]
}

func addedInteger(nums1 []int, nums2 []int) int {
  sort.Sort(IntSlice(nums1))
  sort.Sort(IntSlice(nums2))
  return nums2[0] - nums1[0]
}

func main() {
  var nums1 []int = []int{2, 6, 4}
  var nums2 []int = []int{9, 7, 5}
  fmt.Println(addedInteger(nums1, nums2))
}
