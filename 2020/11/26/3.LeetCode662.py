#!/usr/bin/env python
# coding=utf-8

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: TreeNode, level_node, level: int, ind: int) -> None:
        if (root == None):
            return 
        if (len(level_node) == level):
            level_node.append(list())
        level_node[level].append(ind)
        self.dfs(root->left, level_node, level + 1, ind * 2)
        self.dfs(root->right, level_node, level + 1, ind * 2 + 1)

    def widthOfBinaryTree(self, root: TreeNode) -> int:
        level_node = list()
        ans = 0
        self.dfs(root, level_node, 0, 1)
        for item in level_node:
            item.sort()
            ans = max(ans, item[-1] - item[0] + 1)
        return ans
