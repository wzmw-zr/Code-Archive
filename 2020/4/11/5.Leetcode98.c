/*************************************************************************
	> File Name: 5.Leetcode98.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月11日 星期六 21时55分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *lchild, *rchild;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
} Tree;

typedef struct Node {
    bool flag;
    long max_n, min_n;
} Node;

TreeNode *InitTreeNode(int val) {
    TreeNode *node = (TreeNode *) calloc(sizeof(TreeNode), 1);
    node->val = val;
    return node;
}

Tree *InitTree() {
    Tree *tree = calloc(sizeof(Tree), 1);
    return tree;
}

TreeNode *Insert(int val, TreeNode *root) {
    if (!root) return InitTreeNode(val);
    if (root->val == val) return root;
    if (root->val < val) root->rchild = Insert(val, root->rchild);
    if (root->val > val) root->lchild = Insert(val, root->lchild);
    return root;
}

void FreeTreeNode(TreeNode *root) {
    if (!root) return ;
    FreeTreeNode(root->lchild);
    FreeTreeNode(root->rchild);
    free(root);
}

void FreeTree(Tree *tree) {
    FreeTreeNode(tree->root);
} 

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int getMax(TreeNode *root) {
    if (!root) return INT32_MIN;
    int l_max = getMax(root->lchild);
    int r_max = getMax(root->rchild);
    return max(root->val, max(l_max, r_max));
}

int getMin(TreeNode *root) {
    if (!root) return INT32_MAX;
    int l_min = getMin(root->lchild);
    int r_min = getMin(root->rchild);
    return min(root->val, min(l_min, r_min));
}

Node Check(TreeNode *root) {
    if (!root) {
        Node ret = {true, INT64_MAX, INT64_MIN};
        return ret;
    }
    Node left = Check(root->lchild);
    Node right = Check(root->rchild);
    Node ret;
    ret.flag = root->val > left.max_n && root->val < right.min_n;
    ret.min_n = min(root->val, min(left.min_n, right.min_n));
    ret.max_n = max(root->val, max(left.max_n, right.max_n));
    return ret;
}

int isValidBST(TreeNode *root) {
    if (!root) return 1;
    int l_max = getMax(root->lchild);
    int r_min = getMin(root->rchild);
    if (root->val > l_max && root->val < r_min) return 1;
    return 0;
}

int main() {
    Tree *tree = InitTree();
    tree->root = InitTreeNode(5);
    FreeTree(tree);
    return 0;
}
