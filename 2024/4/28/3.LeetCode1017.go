package main

import "fmt"

func abs(x int) int {
  if x >= 0 {
    return x
  }
  return x * -1
}

func reverse(arr []byte) {
  for i, j := 0, len(arr) - 1; i < j; i, j = i + 1, j - 1 {
    arr[i], arr[j] = arr[j], arr[i]
  }
}

func baseNeg2(n int) string {
  if n == 0 {
    return "0"
  }
  var ans []byte = make([]byte, 0)
  for n != 0 {
    var r int = abs(n % -2)
    ans = append(ans, byte(r + '0'))
    n = (n - r) / -2
  }
  reverse(ans)
  return string(ans)
}

func main() {
  var n int
  fmt.Scanf("%d", &n)
  fmt.Println(baseNeg2(n))
}
