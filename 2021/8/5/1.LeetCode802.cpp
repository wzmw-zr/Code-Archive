/*************************************************************************
	> File Name: 1.LeetCode802.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月05日 星期四 00时07分40秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    vector<int> next;
    int in_degree;
    Node() : next(vector<int>{}), in_degree(0) {}
};

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].in_degree = graph[i].size();
        for (int x : graph[i]) nodes[x].next.push_back(i);
    }
    queue<int> que;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nodes[i].in_degree) continue;
        que.push(i);
    }
    while (!que.empty()) {
        int t = que.front();
        ans.push_back(t);
        que.pop();
        for (int ind : nodes[t].next) {
            if (!(--nodes[ind].in_degree)) que.push(ind);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
