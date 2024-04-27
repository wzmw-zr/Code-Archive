package main

import (
  "fmt"
  "container/heap"
)

type Node struct {
  id int
  dist int
}

type PriorityQueue []Node

func (p PriorityQueue) Len() int {
  return len(p)
}

func (p PriorityQueue) Less(i, j int) bool {
  if p[i].dist == p[j].dist {
    return p[i].id < p[j].id
  }
  return p[i].dist < p[j].dist
}

func (p PriorityQueue) Swap(i, j int) {
  p[i], p[j] = p[j], p[i]
}

func (p *PriorityQueue) Push(v interface{}) {
  item := v.(Node)
  *p = append(*p, item)
}

func (p *PriorityQueue) Pop() interface{} {
  var tmp PriorityQueue = *p
  var length = len(tmp)
  *p = tmp[: length - 1]
  return tmp[length - 1]
}

func main() {
  var pq PriorityQueue = PriorityQueue{
    {1, 10},
    {2, 10},
    {3, 20},
    {4, 50},
    {6, 0},
  }
  heap.Init(&pq)
  fmt.Println(pq)
  for len(pq) > 0 {
    fmt.Println(heap.Pop(&pq))
  }
}
