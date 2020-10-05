/*************************************************************************
	> File Name: 1.LeetCode987.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月05日 星期一 07时28分25秒
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

    TreeNode() = default;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

void border(TreeNode *root, int ind, int &mmax, int &mmin) {
    if (!root) return ;
    mmax = max(ind, mmax);
    mmin = min(ind, mmin);
    border(root->left, ind - 1, mmax, mmin);
    border(root->right, ind + 1, mmax, mmin);
}

int getHeight(TreeNode *root) {
    if (!root) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

//typedef pair<TreeNode *, int> PTI;

struct Node {
    TreeNode *node;
    int h, ind;

    Node() = default;
    Node(TreeNode *node, int h, int ind) : node(node), h(h), ind(ind) {}
    bool operator<(Node &b) {
        return this->h == b.h ? this->node->val < b.node->val : this->h < b.h;
    }
};

void dfs(TreeNode *root, int h, int ind, vector<vector<Node>> &temp) {
    if (!root) return ;
    temp[ind].push_back(Node(root, h, ind));
    dfs(root->left, h + 1, ind - 1, temp);
    dfs(root->right, h + 1, ind + 1, temp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    int mmax = INT32_MIN, mmin = INT32_MAX;
    border(root, 0, mmax, mmin);
    int height = getHeight(root);
    vector<vector<Node>> temp(mmax - mmin + 1, vector<Node>(0));
    dfs(root, 0, mmin * -1, temp);
    for (auto &x : temp) sort(x.begin(), x.end());
    vector<vector<int>> ans(mmax - mmin + 1, vector<int>(0));
    for (int i = 0; i < temp.size(); i++) {
        for (auto &x : temp[i]) {
            ans[i].push_back(x.node->val);
        }
    }
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto ans = verticalTraversal(root);
    for (auto &x : ans) {
        cout << "[";
        for (auto &y : x) cout << y << ", ";
        cout << "]" << endl;
    }
    return 0;
}
