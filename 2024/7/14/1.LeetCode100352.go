package main

import (
  "fmt"
)

func getSmallestString(s string) string {
  n := len(s)
  bytes := []byte(s)
  for i := 0; i < n - 1; i++ {
    if (int(bytes[i] - '0') + int(bytes[i + 1] - '0')) % 2 == 0 && bytes[i] > bytes[i + 1] {
      bytes[i], bytes[i + 1] = bytes[i + 1], bytes[i]
      break
    }
  }
  return string(bytes)
}

func main() {
  s := "45320"
  fmt.Println(getSmallestString(s))
}
