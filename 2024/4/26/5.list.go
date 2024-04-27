package main

import (
  "fmt"
  "container/list"
)

func main() {
  var x *list.List = list.New()
  x.PushFront("Hello")
  x.PushBack(1)
  for e := x.Front(); e != nil; e = e.Next() {
    fmt.Println(e.Value)
  }
}
