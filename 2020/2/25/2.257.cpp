/*************************************************************************
	> File Name: 2.257.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 10时41分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *NewTreeNode(int val) {
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    t->val = val;
    t->left = t->right = NULL;
    return t;
}

int count_path(struct TreeNode *root) {
    if (!root->left && !root->right) return 1;
    if (!root->left) return count_path(root->right); 
    if (!root->right) return count_path(root->left);
    return count_path(root->left) + count_path(root->right);
}

int max_height(struct TreeNode *root) {
    if (!root) return 0;
    int left = max_height(root->left);
    int right = max_height(root->right);
    return 1 + (left > right ? left : right);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    if (!root->left && !root->right) {
        *returnSize = 1;
        char **ret = (char **) malloc(sizeof(char *) * 1);
        ret[0] = (char *) malloc(sizeof(char) * 5);
        sprintf(ret[0], "%d", root->val);
        return ret;
    }
    int left, right;
    char **left_path, **right_path;
    left_path = binaryTreePaths(root->left, &left);
    right_path = binaryTreePaths(root->right, &right);
    int path_cnt = count_path(root), h = max_height(root);
    char **ret = (char **) malloc(sizeof(char *) * path_cnt);
    for (int i = 0; i < path_cnt; i++) {
        ret[i] = (char *) calloc(sizeof(char), 4 * h);    
        sprintf(ret[i], "%d->", root->val);
    }
    int i, j;
    for (i = 0; i < left; i++) strcat(ret[i], left_path[i]);
    for (int j = 0; j < right; j++) strcat(ret[i + j], right_path[j]);
    *returnSize = left + right;
    return ret;
}

int main() {
    TreeNode *root = NewTreeNode(37); 
    root->left = NewTreeNode(-34);
    root->right = NewTreeNode(48);
    root->left->right = NewTreeNode(-100);
    root->right->left = NewTreeNode(-100);
    root->right->right = NewTreeNode(48);
    root->right->right->left = NewTreeNode(-54);
    root->right->right->left->left = NewTreeNode(-71);
    root->right->right->left->right = NewTreeNode(-22);
    root->right->right->left->right->right = NewTreeNode(8);
    char **ret;
    int returnSize;
    ret = binaryTreePaths(root, &returnSize);
    for (int i = 0; i < returnSize; i++) printf("%s\n", ret[i]);
    return 0;
}
