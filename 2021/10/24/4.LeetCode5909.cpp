/*************************************************************************
	> File Name: 4.LeetCode5909.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月24日 星期日 11时20分21秒
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
    int id;
    int in_degree;
    int cost;
    int s_time;
    vector<int> next;

    Node() = default;
    Node(int id, int cost) : id(id), in_degree(0), cost(cost), s_time(0) {}
};

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<Node> nodes(n + 1);
    for (int i = 0; i < n; i++) nodes[i + 1].cost = time[i];
    for (auto rel : relations) {
        nodes[rel[1]].in_degree++;
        nodes[rel[0]].next.push_back(rel[1]);
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (!nodes[i].in_degree) que.push(i);
    }
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        nodes[t].s_time += nodes[t].cost;
        for (int x : nodes[t].next) {
            if (!(--nodes[x].in_degree)) que.push(x);
            nodes[x].s_time = max(nodes[x].s_time, nodes[t].s_time);
        }
    }
    int ans = INT32_MIN;
    for (int i = 1; i <= n; i++) ans = max(ans, nodes[i].s_time);
    return ans;
}

int main() {
    return 0;
}
