package main

import "fmt"


func distanceTraveled(mainTank int, additionalTank int) int {
  var ans int
  for mainTank >= 5 && additionalTank > 0 {
    mainTank -= 4
    additionalTank--
    ans += 5
  }
  ans += mainTank
  return ans * 10
}


func main() {
  fmt.Println(distanceTraveled(5, 10))
  fmt.Println(distanceTraveled(1, 2))
}
