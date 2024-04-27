package main

import "fmt"

func numberOfSpecialChars(word string) int {
  var l_ind, u_ind []int
  l_ind = make([]int, 26)
  u_ind = make([]int, 26)
  for i := 0; i < 26; i++ {
    l_ind[i] = -1
    u_ind[i] = -1
  }
  for ind, ch := range word {
    if ch >= 'a' {
      l_ind[ch - 'a'] = ind
    } else {
      if u_ind[ch - 'A'] == -1 {
        u_ind[ch - 'A'] = ind
      }
    }
  }
  var ans int
  for i := 0; i < 26; i++ {
    if l_ind[i] == -1 || u_ind[i] == -1 {
      continue
    }
    if l_ind[i] < u_ind[i] {
      ans++
    }
  }
  return ans
}

func main() {
  var word string
  fmt.Scanf("%s", &word)
  fmt.Println(numberOfSpecialChars(word))
}
