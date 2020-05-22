/*************************************************************************
	> File Name: 1.LeetCode105.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月22日 星期五 07时04分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *build(vector<int> &preorder, int p_l, int p_r, vector<int> &inorder, int i_l, int i_r){
    if (p_l > p_r) return NULL;
    //cout << preorder[l] << " ";
    TreeNode *root = (TreeNode *) calloc(sizeof(TreeNode), 1);
    root->val = preorder[p_l];
    //cout << root->val << endl;
    int ind = 0;
    while (inorder[i_l + ind] != preorder[p_l]) ind++;
    root->left = build(preorder, p_l + 1, p_l + ind, inorder, i_l, i_l + ind - 1);
    root->right = build(preorder, p_l + ind + 1, p_r, inorder, i_l + ind + 1, i_r);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //if (preorder.size() == 0) return NULL;
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
}

void in_traverse(TreeNode *root) {
    if (!root) return ;
    cout << root->val << " ";
    in_traverse(root->left);
    in_traverse(root->right);
}

int main() {
    int n, t;
    cin >> n;
    vector<int> preorder, inorder;
    for (int i = 0; i < n; i++) cin >> t, preorder.push_back(t);
    for (int i = 0; i < n; i++) cin >> t, inorder.push_back(t);
    TreeNode *root = buildTree(preorder, inorder);
    in_traverse(root);
    return 0;
}
