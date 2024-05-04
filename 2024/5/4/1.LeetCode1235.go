package main

import (
  "fmt"
  "slices"
  "container/heap"
  "math"
)

type Node struct {
  q int
  w int
}

type NodeList []Node

func (n NodeList) Len() int {
  return len(n)
}

func (n NodeList) Swap(i, j int) {
  n[i], n[j] = n[j], n[i]
}

func (n NodeList) Less(i, j int) bool {
  if n[i].q == n[j].q {
    return n[i].w > n[j].w
  }
  return n[i].q > n[j].q
}

func (n *NodeList) Push(node any) {
  *n = append(*n, node.(Node))
}

func (n *NodeList) Pop() any {
  var l int = len(*n)
  var ret any
  *n, ret = (*n)[:l - 1], (*n)[l - 1]
  return ret
}

func mincostToHireWorkers(quality []int, wage []int, k int) float64 {
  var l int = len(quality)
  var nodes []Node = make([]Node, l)
  for i := 0; i < l; i++ {
    nodes[i].q = quality[i]
    nodes[i].w = wage[i]
  }
  slices.SortFunc(nodes, func(a, b Node) int {
    if a.w * b.q < b.w * a.q {
      return -1
    } else if a.w * b.q > b.w * a.q {
      return 1
    } else {
      if a.w == b.w {
        return 0
      } else if a.w < b.w {
        return 1
      } else {
        return -1
      }
    }
  })
  fmt.Println(nodes)
  var node_list NodeList = NodeList(make([]Node, 0))
  heap.Init(&node_list)
  var sumQ float64 = 0
  for i := 0; i < min(k - 1, l); i++ {
    heap.Push(&node_list, nodes[i])
    sumQ += float64(nodes[i].q)
  }
  var ans float64 = float64(math.MaxInt)
  for i := k - 1; i < l; i++ {
    sumQ += float64(nodes[i].q)
    var frac float64 = float64(nodes[i].w) / float64(nodes[i].q)
    ans = min(ans, sumQ * frac)
    heap.Push(&node_list, nodes[i])
    t := heap.Pop(&node_list)
    sumQ -= float64((t.(Node)).q)
  }
  return ans
}

func main() {
  // var quality []int = []int{10, 20, 5}
  // var wage []int = []int{70, 50, 30}
  // var k int = 2
  var quality []int = []int{25,68,35,62,52,57,35,83,40,51}
  var wage []int = []int{147,97,251,129,438,443,120,366,362,343}
  var k int = 6
  fmt.Println(mincostToHireWorkers(quality, wage, k))
}
