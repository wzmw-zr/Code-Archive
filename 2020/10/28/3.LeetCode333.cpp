/*************************************************************************
	> File Name: 3.LeetCode333.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月28日 星期三 16时05分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

struct Node {
    int mmax;
    int mmin;
    int cnt;
    int flag;
    Node() : mmax(INT32_MIN), mmin(INT32_MAX), cnt(0), flag(1) {};
    Node(int mmax, int mmin, int cnt, int flag) : mmax(mmax), mmin(mmin), cnt(cnt), flag(flag) {}
};

Node dfs(TreeNode *root, int &cnt) {
    if (!root) return Node();
    if (!root->left && !root->right) 
        return Node(root->val, root->val, 1, 1);
    Node left = dfs(root->left, cnt);
    Node right = dfs(root->right, cnt);
    int mmin = min(root->val, min(left.mmin, right.mmin));
    int mmax = max(root->val, max(left.mmax, right.mmax));
    int num = left.cnt + right.cnt + 1;
    if (!left.flag || !right.flag) 
        return Node(mmin, mmax, num, 0);
    if ((root->val <= left.mmax) || (root->val >= right.mmin)) 
        return Node(mmin, mmax, num, 0);
    cnt = max(cnt, num);
    return Node(mmin, mmax, num, 1);
}

int largestBSTSubtree(TreeNode* root) {
    int cnt = 0;
    dfs(root, cnt);
    return cnt;
}

int main() {
    return 0;
}
