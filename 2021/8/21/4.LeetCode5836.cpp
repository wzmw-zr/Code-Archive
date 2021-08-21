/*************************************************************************
	> File Name: 3.LeetCode5836.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月21日 星期六 23时12分17秒
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

// TLE
using PIL = pair<int, long>;

const long MOD = 1e9 + 7;

struct Node {
    int ind;
    long dis;

    Node() = default;
    Node(int ind, long dis) : ind(ind), dis(dis) {}

    bool operator<(const struct Node &that) const {
        return this->dis > that.dis;
    }
};

long dfs(int ind, vector<vector<PIL>> &graph, unordered_map<int, unordered_map<long, long>> &mp, long dis) {
    if (ind == 0) {
        if (dis == 0) return 1;
        return 0;
    }
    long cnt = 0;
    for (auto &&[next_ind, l] : graph[ind]) {
        if (l <= dis) cnt += dfs(next_ind, graph, mp, dis - l);
    }
    cnt %= MOD;
    mp[ind][dis] = cnt;
    return cnt;
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<PIL>> graph(n, vector<PIL>(0));
    for (auto r : roads) {
        graph[r[0]].push_back(PIL(r[1], r[2]));
        graph[r[1]].push_back(PIL(r[0], r[2]));
    }
    priority_queue<Node> que;
    que.push(Node(0, 0));
    long min_dis = INT64_MAX;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.ind == n - 1) {
            min_dis = temp.dis;   
            break;
        }
        for (auto &&[ind, dis] : graph[temp.ind]) que.push(Node(ind, temp.dis + dis));
    }
    unordered_map<int, unordered_map<long, long>> mp;
    for (int i = 0; i < n; i++) mp[i] = unordered_map<long, long>();
    dfs(n- 1, graph, mp, min_dis);
    return mp[n - 1][min_dis];
}

int main() {
    int n;
    int a, b, c;
    cin >> n;
    vector<vector<int>> roads;
    while (cin >> a >> b >> c) roads.push_back({a, b, c});
    cout << countPaths(n, roads) << endl;
    return 0;
}
