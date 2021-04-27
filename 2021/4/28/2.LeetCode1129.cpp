/*************************************************************************
	> File Name: 2.LeetCode1129.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月28日 星期三 00时16分15秒
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

#define RED 0
#define BLUE 1

struct Node {
    int color;
    int dis;
    int ind;
    Node() = default;
    Node(int ind, int dis, int color) : ind(ind), dis(dis), color(color) {}
};

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
    unordered_map<int, unordered_set<int>> red, blue;
    for (int i = 0; i < n; i++) {
        red[i] = unordered_set<int>();
        blue[i] = unordered_set<int>();
    }
    for (auto &x : red_edges) red[x[0]].insert(x[1]);
    for (auto &x : blue_edges) blue[x[0]].insert(x[1]);   
    vector<int> red_edge_pre(n, INT32_MAX);
    vector<int> blue_edge_pre(n, INT32_MAX);
    queue<Node> que;
    for (int x : red[0]) {
        red_edge_pre[x] = 1;
        que.push(Node(x, 1, RED));
    }
    for (int x : blue[0]) {
        blue_edge_pre[x] = 1;
        que.push(Node(x, 1, BLUE));   
    }
    red_edge_pre[0] = blue_edge_pre[0] = 0;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        if (temp.color == RED) {
            for (int x : blue[temp.ind]) {
                if (blue_edge_pre[x] != INT32_MAX) continue;
                blue_edge_pre[x] = temp.dis + 1;
                que.push(Node(x, temp.dis + 1, BLUE));
            }
        } else {
            for (int x : red[temp.ind]) {
                if (red_edge_pre[x] != INT32_MAX) continue;
                red_edge_pre[x] = temp.dis + 1;
                que.push(Node(x, temp.dis + 1, RED));
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int t = min(red_edge_pre[i], blue_edge_pre[i]);
        ans[i] = t == INT32_MAX ? -1 : t;
    }
    return ans;
}

int main() {
    return 0;
}
