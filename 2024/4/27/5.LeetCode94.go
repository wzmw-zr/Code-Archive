package main

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
  var dfs func(*TreeNode)
  var ans []int = make([]int, 0)
  dfs = func(node *TreeNode) {
    if node == nil {
      return
    }
    dfs(node.Left)
    ans = append(ans, node.Val)
    dfs(node.Right)
  }
  dfs(root)
  return ans
}
