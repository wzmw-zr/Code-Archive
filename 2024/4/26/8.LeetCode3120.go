package main

import "fmt"

func numberOfSpecialChars(word string) int {
  var mp map[rune]int = make(map[rune]int)
  var ans int
  for _, ch := range word {
    mp[ch] = 1
  }
  for ch := 'a'; ch <= 'z'; ch++ {
    _, ok1 := mp[rune(ch)]
    _, ok2 := mp[rune(ch) - 32]
    if ok1 && ok2 {
      ans++
    }
  }
  return ans
}

func main() {
  var word string
  fmt.Scanf("%s", &word)
  fmt.Println(word)
  fmt.Println(numberOfSpecialChars(word))
}
