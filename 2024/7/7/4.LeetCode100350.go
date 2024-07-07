package main

import (
  "fmt"
  "math"
)

type Node struct {
  isEnd bool
  cost int
  next []*Node
}

func NewNode() *Node {
  node := &Node{}
  node.next = make([]*Node, 26)
  return node
}

func buildTree(words []string, costs []int) *Node {
  n := len(words)
  root := NewNode()
  for i := 0; i < n; i++ {
    node := root
    for j := 0; j < len(words[i]); j++ {
      idx := int(words[i][j] - 'a')
      node.next[idx] = NewNode()
      node = node.next[idx]
    }
    node.isEnd = true
    node.cost = costs[i]
  }
  return root
}

func PrintNode(node *Node) {
  arrs := make([]byte, 0, 26)
  for i := 0; i < 26; i++ {
    if node.next[i] == nil {
      continue
    }
    arrs = append(arrs, byte(i + 'a'))
  }
  fmt.Printf("%s ", string(arrs))
}

func printTree(root *Node) {
  que := make([]*Node, 0)
  que = append(que, root)
  for len(que) > 0 {
    n := len(que)
    for i := 0; i < n; i++ {
      PrintNode(que[i])
      for j := 0; j < 26; j++ {
        if que[i].next[j] == nil {
          continue
        }
        que = append(que, que[i].next[j])
      }
    }
    que = que[n:]
    fmt.Printf("\n")
  }
}

func minimumCost(target string, words []string, costs []int) int {
  _root := buildTree(words, costs)
  printTree(_root)
  ans := math.MaxInt
  var dfs func(root *Node, idx int, totalCost int)
  dfs = func(root *Node, idx int, totalCost int) {
    if len(target) == idx {
      if root.isEnd {
        ans = min(ans, totalCost)
      }
      return
    }
    if root.isEnd {
      dfs(_root, idx, totalCost)
    }
    ind := int(target[idx] - 'a')
    if root.next[ind] != nil {
      dfs(root.next[ind], idx + 1, totalCost + root.next[ind].cost)
    }
  }
  dfs(_root, 0, 0)
  return ans
}

func main() {
  target := "abcdef"
  words := []string{"abdef","abc","d","def","ef"}
  costs := []int{100,1,1,10,5}
  fmt.Println(minimumCost(target, words, costs))
}
