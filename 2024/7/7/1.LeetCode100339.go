package main

import (
  "fmt"
)

func getEncryptedString(s string, k int) string {
  n := len(s)
  k %= n
  s += s
  return s[k: k + n]
}
