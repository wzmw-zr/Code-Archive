package main

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}


func dfs(root *TreeNode, ans *[]int) {
  if root == nil {
    return
  }
  dfs(root.Left, ans)
  *ans = append(*ans, root.Val)
  dfs(root.Right, ans)
}

func inorderTraversal(root *TreeNode) []int {
  var ans []int = make([]int, 0)
  dfs(root, &ans)
  return ans
}


func main() {
}
