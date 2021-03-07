/*************************************************************************
	> File Name: 3.LeetCode5699.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月07日 星期日 10时50分59秒
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
    int ind;
    unordered_map<int, int> to;
    long dis;
    Node() = default;
    Node(int ind) : ind(ind), dis(INT64_MAX) {}
    bool operator<(const struct Node &a) const {
        return this->dis > a.dis;
    }
};

void dfs(vector<Node> &nodes, int ind, int &target, int &ans, long pre) {
    if (ind == target) {
        ans++;
        return ;
    }
    if (nodes[ind].dis >= pre) return ;
    for (auto &&[ind_t, dis_t] : nodes[ind].to) 
        dfs(nodes, ind_t, target, ans, nodes[ind].dis);
}

int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    vector<Node> nodes;
    for (int i = 0; i <= n; i++) nodes.push_back(Node(n));
    for (auto &edge : edges) {
        nodes[edge[0]].to[edge[1]] = edge[2];
        nodes[edge[1]].to[edge[0]] = edge[2];
    }
    priority_queue<Node> que;
    nodes[n].dis = 0;
    que.push(nodes[n]);
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        for (auto &&[ind, dis] : temp.to) {
            if (nodes[ind].dis <= temp.dis + dis) continue;
            nodes[ind].dis = temp.dis + dis;
            que.push(nodes[ind]);
        }
    }
    int ans = 0;
    dfs(nodes, 1, n, ans, INT64_MAX);
    return ans;
}

int main() {
    return 0;
}
