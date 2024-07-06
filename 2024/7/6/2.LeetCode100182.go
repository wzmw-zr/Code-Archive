package main

import (
  "fmt"
  "slices"
)

func maximumPoints(enemyEnergies []int, currentEnergy int) int64 {
  n := len(enemyEnergies)
  slices.Sort(enemyEnergies)
  if currentEnergy < enemyEnergies[0] {
    return 0
  }
  sum := int64(currentEnergy)
  for i := 1; i < n; i++ {
    sum += int64(enemyEnergies[i])
  }
  return sum / int64(enemyEnergies[0])
}
