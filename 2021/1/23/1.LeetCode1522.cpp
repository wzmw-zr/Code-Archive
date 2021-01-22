/*************************************************************************
	> File Name: 1.LeetCode1522.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月23日 星期六 00时05分41秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int dfs(Node *root, int &ans) {
    if (!root) return 0;
    if (root->children.size() == 0) return 1;
    int cnt = 0;
    vector<int> height;
    for (auto &x : root->children) {
        int temp = dfs(x, ans);
        cnt = max(cnt, temp);
        height.push_back(temp);
    }
    sort(height.begin(), height.end());
    int n = height.size();
    if (n == 1) ans = max(ans, height[0]);
    else ans = max(ans, height[n - 1] + height[n - 2]);
    return cnt + 1;
}

int diameter(Node* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int main() {
    return 0;
}
