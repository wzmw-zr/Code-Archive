package main

import "fmt"

func baseNeg2(n int) string {
  var d []int = make([]int, 0)
  for {
    d = append(d, n & 1)
    n >>= 1
    if n == 0 {
      break
    }
  }

  for i := 0; i < len(d); i++ {
    if (i & 1) == 1 && d[i] == 1 {
      if i + 1 == len(d) {
        d = append(d, 0)
      }
      d[i + 1]++
    }
  }

  for i := 0; i < len(d); i++ {
    if (i & 1) == 0 && d[i] >= 2 {
      d[i] -= 2
      if i + 1 == len(d) {
        d = append(d, 0)
      }
      if d[i + 1] == 0 {
        if i + 2 == len(d) {
          d = append(d, 0)
        }
        d[i + 1]++
        d[i + 2]++
      } else {
        d[i + 1]--
      }
    }
  }

  var s []rune = make([]rune, len(d))
  for idx, ch := range d {
    s[len(d) - 1 - idx] = rune(ch + '0')
  }

  return string(s)
}

func main() {
  var n int
  fmt.Scanf("%d", &n)
  fmt.Println(baseNeg2(n))
}
