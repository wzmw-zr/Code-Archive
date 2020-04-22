/*************************************************************************
	> File Name: 1.LeetCode199.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月22日 星期三 07时21分45秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct Node {
    TreeNode *node;
    int height;
} Node;

TreeNode *GetNewNode(int x) {
    TreeNode *node = (TreeNode *) calloc(sizeof(TreeNode), 1);
    node->val = x;
    return node;
}

vector<int> rightSideView(TreeNode *root) {
    vector<int> ret;
    int level = 0;
    if (!root) return ret;
    queue<Node> que;
    que.push({root, 1});
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        if (temp.height > level) {
            level = temp.height;
            ret.push_back((temp.node)->val);
        }
        if ((temp.node)->right) que.push({(temp.node)->right, temp.height + 1});
        if ((temp.node)->left) que.push({(temp.node)->left, temp.height + 1});
    }
    return ret;
}

void clear(TreeNode *root) {
    if (!root) return ;
    clear(root->left);
    clear(root->right);
    free(root);
}

int main() {
    TreeNode *root = GetNewNode(1);
    root->left= GetNewNode(2);
    root->left->right= GetNewNode(5);
    root->right= GetNewNode(3);
    root->right->right= GetNewNode(4);
    vector<int> res = rightSideView(root);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}
