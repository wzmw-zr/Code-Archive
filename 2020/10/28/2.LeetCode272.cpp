/*************************************************************************
	> File Name: 2.LeetCode272.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月28日 星期三 15时51分53秒
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
    int val;
    double dis;

    Node() = default;
    Node(int val, double dis) : val(val), dis(dis) {}

    bool operator<(const struct Node &b) const {
        return this->dis < b.dis;
    }
};

void dfs(TreeNode *root, double target, priority_queue<Node> &nodes) {
    if (!root) return ;
    dfs(root->left, target, nodes);
    nodes.push(Node(root->val, abs(target - root->val * 1.0)));
    dfs(root->right, target, nodes);
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<Node> nodes;
    vector<int> ans;
    dfs(root, target, nodes);
    for (int i = 0; i < k; i++) {
        Node temp = nodes.top();
        nodes.pop();
        ans.push_back(temp.val);
    }
    return ans;
}

int main() {
    return 0;
}
