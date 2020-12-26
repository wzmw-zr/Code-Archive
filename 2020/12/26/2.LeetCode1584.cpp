/*************************************************************************
	> File Name: 2.LeetCode1584.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月26日 星期六 08时34分32秒
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
    int x, y;
    Node() = default;
    Node(int x, int y) : x(x), y(y) {}
    Node(const Node &a) : x(a.x), y(a.y) {}
    int operator-(const struct Node &a) const {
        return abs(this->x - a.x) + abs(this->y - a.y);
    }
    string to_str() {
        string ans = to_string(x) + "," + to_string(y);
        return ans;
    }
};

struct Distance {
    string node_1, node_2;
    int dis;
    Distance() = default;
    Distance(string node_1, string node_2, int dis) : node_1(node_1), node_2(node_2), dis(dis) {}
    bool operator<(const struct Distance &x) const {
        return this->dis > x.dis;
    } 
};

struct UnionSet {
    int n;
    vector<int> fa;
    UnionSet(int n) : n(n), fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    } 
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    bool merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return false;
        fa[a] = b;
        n--;
        return true;
    }
};

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<Node> nodes;
    vector<string> nodes_str;
    int ind = 0, n = points.size();
    unordered_map<string, int> mp;
    for (auto x : points) nodes.push_back(Node(x[0], x[1]));
    for (Node &x : nodes) nodes_str.push_back(x.to_str());
    for (string &x : nodes_str) mp[x] = ++ind;
    UnionSet u(n);
    priority_queue<Distance> que;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            que.push(Distance(nodes_str[i], nodes_str[j], nodes[i] - nodes[j]));
        }
    }
    int ans = 0;
    while (!que.empty() && (u.n != 1)) {
        Distance temp = que.top();
        que.pop();
        int x = mp[temp.node_1];
        int y = mp[temp.node_2];
        if (u.merge(x, y)) ans += temp.dis;
    }
    return ans;
}

int main() {
    return 0;
}
