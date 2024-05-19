package main

import (
  "fmt"
)

func isValid(word string) bool {
  if len(word) < 3 {
    return false
  }
  var valid map[rune]bool = make(map[rune]bool)
  for i := '0'; i <= '9'; i++ {
    valid[i] = true
  }
  for i := 'a'; i <= 'z'; i++ {
    valid[i] = true
  }
  for i := 'A'; i <= 'Z'; i++ {
    valid[i] = true
  }
  for _, ch := range(word) {
    if _, ok := valid[ch]; !ok {
      return false
    }
  }

  var vowel map[rune]bool = map[rune]bool{
    'a': true, 'e': true, 'i': true, 'o': true, 'u': true,
    'A': true, 'E': true, 'I': true, 'O': true, 'U': true,
  }
  var vowel_cnt int
  var consonant_cnt int
  for _, ch := range(word) {
    if _, ok := vowel[ch]; ok {
      vowel_cnt++
    } else if (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') {
      consonant_cnt++
    }
  }
  if vowel_cnt >= 1 && consonant_cnt >= 1 {
    return true
  }
  return false
}

func main() {
  var word string
  fmt.Scanf("%s", &word)
  fmt.Println(isValid(word))
}
