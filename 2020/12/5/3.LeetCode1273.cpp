/*************************************************************************
	> File Name: 3.LeetCode1273.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月05日 星期六 20时36分47秒
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

struct Node {
    int val;
    vector<Node *> child;
    Node() = default;
    Node(int val) : val(val) {}
};

typedef pair<int, int> PII;

PII dfs(Node *root) {
    if (!root) return PII(0, 0);
    int sum = root->val, cnt = 1;
    for (auto x : root->child) {
        auto ans = dfs(x);
        sum += ans.first;
        cnt += ans.second;
    }
    if (sum == 0) return PII(0, 0);
    return PII(sum, cnt);
}

int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    vector<Node *> node;
    for (int x : value) node.push_back(new Node(x));
    for (int i = 1; i < parent.size(); i++) {
        node[parent[i]]->child.push_back(node[i]);
    }
    PII ans = dfs(node[0]);
    return ans.first;
}

int main() {
    return 0;
}
