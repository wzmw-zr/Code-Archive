package main

import (
  "fmt"
  "math"
)

func minimumOperationsToMakeKPeriodic(word string, k int) int {
  var mp map[string]int = make(map[string]int)
  for i := 0; i < len(word); i += k {
    mp[word[i: i + k]]++
  }
  var ans int = math.MaxInt
  for _, cnt := range mp {
    ans = min(ans, len(word) / k - cnt)
  }
  return ans
}

func main() {
  var word string
  var k int
  fmt.Scanf("%s", &word)
  fmt.Scanf("%d", &k)
  fmt.Println(minimumOperationsToMakeKPeriodic(word, k))
}
