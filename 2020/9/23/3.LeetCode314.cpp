/*************************************************************************
	> File Name: 3.LeetCode314.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月23日 星期三 09时38分35秒
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

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Node {
    TreeNode *root;
    int column;
};

void build(TreeNode *root, int &mmin, int &mmax, int column) {
    if (!root) return ;
    mmin = min(mmin, column);
    mmax = max(mmax, column);
    build(root->left, mmin, mmax, column - 1);
    build(root->right, mmin, mmax, column + 1);
}

vector<vector<int>> verticalOrder(TreeNode* root) {
    int mmin = INT32_MAX, mmax = INT32_MIN;
    build(root, mmin, mmax, 0);
    vector<vector<int>> ans(mmax - mmin + 1, vector<int>(0, 0));
    queue<Node> que;
    if (root) que.push({root, mmin * -1});
    while (!que.empty()) {
        auto x = que.front();
        que.pop();
        ans[x.column].push_back(x.root->val);
        if (x.root->left) que.push({x.root->left, x.column - 1});
        if (x.root->right) que.push({x.root->right, x.column + 1});
    }
    return ans;
}

int main() {
    return 0;
}
