package main

import "fmt"

func baseNeg2(n int) string {
  var digits []int = make([]int, 0)
  for {
    digits = append(digits, n & 1)
    n >>= 1
    if n == 0 {
      break
    }
  }
  for i := 0; i < len(digits); i++ {
    if digits[i] == 1 && (i & 1) == 1 {
      if i + 1 == len(digits) {
        digits = append(digits, 0)
      }
      digits[i + 1]++
    }
  }
  for i := 0; i < len(digits); i++ {
    if (i & 1) == 0 && digits[i] >= 2 {
      if i + 1 == len(digits) {
        digits = append(digits, 0)
      }
      if digits[i + 1] == 1 {
        digits[i + 1] = 0
        digits[i] = digits[i] % 2
      } else {
        digits[i] %= 2
        digits[i + 1] = 1
        if i + 2 == len(digits) {
          digits = append(digits, 1)
        }
      }
    }
  }
  for i := 0; i < len(digits); i++ {
    digits[i] += '0'
  }
  for i, j := 0, len(digits) - 1; i < j; i, j = i + 1, j - 1 {
    digits[i], digits[j] = digits[j], digits[i]
  }
  var s []rune = make([]rune, 0, len(digits))
  for _, ch := range digits {
    s = append(s, rune(ch))
  }
  return string(s)
}

func main() {
  var n int
  fmt.Scanf("%d", &n)
  fmt.Println(n)
  fmt.Println(baseNeg2(n))
}
