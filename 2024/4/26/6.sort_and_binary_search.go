package main

import (
  "fmt"
  "sort"
)

type Person struct {
  Name string
  Age int
}

type ArrayOfPerson []Person

func (a ArrayOfPerson) Len() int {
  return len(a)
}

func (a ArrayOfPerson) Less(i, j int) bool {
  if a[i].Age == a[j].Age {
    return a[i].Name < a[j].Name
  }
  return a[i].Age < a[j].Age
}

func (a ArrayOfPerson) Swap(i, j int) {
  a[i], a[j] = a[j], a[i]
}

func main() {
  var listOfPeople ArrayOfPerson = ArrayOfPerson{
    {"Andy", 20},
    {"Peter", 25},
    {"John", 10},
    {"Mike", 10},
  }
  sort.Sort(listOfPeople)
  fmt.Printf("%+v\n", listOfPeople)
  var idx int = sort.Search(len(listOfPeople), func(i int) bool {
    return listOfPeople[i].Age > 21
  })
  fmt.Println(idx)
}
