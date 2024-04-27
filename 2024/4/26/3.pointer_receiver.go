package main

import "fmt"

type Animal interface {
  Voice() string
}

type Dog struct {
  Name string
}

type Cat struct {
  Name string
}

func (d *Dog) Voice() string {
  return "Woff"
}

func (c Cat) Voice() string {
  return "Miao"
}


func main() {
  var a Animal
  var b Dog
  a = &b
  fmt.Println(a.Voice())
  var c Cat
  a = c
  fmt.Println(a.Voice())
}
