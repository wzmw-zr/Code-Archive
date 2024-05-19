package main

import (
  "fmt"
  "slices"
)

func average(salary []int) float64 {
  var ans float64
  slices.Sort(salary)
  salary = salary[1:len(salary) - 1]
  for _, s := range(salary) {
    ans += float64(s)
  }
  ans /= float64(len(salary))
  return ans
}
