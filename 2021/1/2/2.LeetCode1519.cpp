/*************************************************************************
	> File Name: 2.LeetCode1519.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月02日 星期六 00时34分06秒
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

struct TreeNode {
    char c;
    int ind;
    vector<TreeNode *> child;
    TreeNode() = default;
    TreeNode(char c, int ind) : c(c), ind(ind) {}
};

vector<int> dfs(TreeNode *root, unordered_map<TreeNode *, bool> &check, vector<int> &ans) {
    if (check[root]) return vector<int>(26, 0);
    check[root] = true;
    vector<int> res(26, 0);
    res[root->c - 'a']++;
    for (auto &x : root->child) {
        if (check[x]) continue;
        auto temp = dfs(x, check, ans);
        for (int i = 0; i < 26; i++) res[i] += ans[i];
    }
    ans[root->ind] = res[root->c - 'a'];
    return res;
}

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<TreeNode *> nodes(n, nullptr);
    for (int i = 0; labels[i]; i++) nodes[i] = new TreeNode(labels[i], i);
    for (auto &x : edges) {
        nodes[x[0]]->child.push_back(nodes[x[1]]);   
        nodes[x[1]]->child.push_back(nodes[x[0]]);
    }
    unordered_map<TreeNode *, bool> check;
    for (auto ptr : nodes) check[ptr] = false;
    vector<int> ans(n, 0);
    dfs(nodes[0], check, ans);
    return ans;
}

int main() {
    return 0;
}
