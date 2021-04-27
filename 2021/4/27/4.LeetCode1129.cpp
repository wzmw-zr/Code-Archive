/*************************************************************************
	> File Name: 4.LeetCode1129.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月27日 星期二 22时10分33秒
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


// WA

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
    vector<int> red_path(n, INT32_MAX);
    vector<int> blue_path(n, INT32_MAX);
    red_path[0] = blue_path[0] = 0;
    if (red[0].size() > 0) {
        queue<Node> que;
        for (int x : red[0]) que.push(Node(x, 1, RED));
        while (!que.empty()) {
            Node temp = que.front();
            que.pop();
            red_path[temp.ind] = temp.dis;
            if (temp.color == RED) {
                for (int x : blue[temp.ind]) {
                    if (red_path[x] != INT32_MAX) continue;
                    que.push(Node(x, temp.dis + 1, BLUE));
                }
            } else {
                for (int x : red[temp.ind]) {
                    if (red_path[x] != INT32_MAX) continue;
                    que.push(Node(x, temp.dis + 1, RED));
                }
            }
        }
    }
    if (blue[0].size() > 0) {
        queue<Node> que;
        for (int x : blue[0]) que.push(Node(x, 1, BLUE));
        while (!que.empty()) {
            Node temp = que.front();
            que.pop();
            blue_path[temp.ind] = temp.dis;
            if (temp.color == RED) {
                for (int x : blue[temp.ind]) {
                    if (blue_path[x] != INT32_MAX) continue;
                    que.push(Node(x, temp.dis + 1, BLUE));
                }
            } else {
                for (int x : red[temp.ind]) {
                    if (blue_path[x] != INT32_MAX) continue;
                    que.push(Node(x, temp.dis + 1, RED));
                }
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = min(red_path[i], blue_path[i]);
    for (int i = 0; i < n; i++) ans[i] = ans[i] == INT32_MAX ? -1 : ans[i];
    return ans;
}


int main() {
    return 0;
}
