package main

import (
  "log"
)


func main() {
  log.Printf("%T", func(i int) int { return i * i })
  // log.Panicf("%T", func(i int) int { return i * i })
  // log.Fatalf("%T", func(i int) int { return i * i })

  // var logger log.Logger
  log.SetFlags(log.Ldate | log.Ltime | log.Lmicroseconds | log.Llongfile)
  log.Printf("%T", func(i int) int { return i * i })
  // logger.Printf("%T", func(i int) int { return i * i })
}
