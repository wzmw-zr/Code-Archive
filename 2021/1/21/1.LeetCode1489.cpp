/*************************************************************************
	> File Name: 1.LeetCode1489.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月21日 星期四 22时39分52秒
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

struct Edge {
    int ind;
    int from;
    int to;
    int weight;
    Edge() = default;
    Edge(int ind, int from, int to, int weight) : ind(ind), from(from), to(to), weight(weight) {}
    bool operator<(const struct Edge &a) const {
        return this->weight > a.weight;
    }
};

struct UnionSet {
    int n;
    int cnt;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n), cnt(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    bool merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return false;
        fa[a] = b;
        cnt--;
        return true;
    }
    void clear() {
        cnt = n;
        for (int i = 0; i < n; i++) fa[i] = i;
    }
};

int kruscal(UnionSet &u, vector<vector<int>> &edges, vector<bool> &check, int &m, vector<bool> &appear, vector<int> &indices) {
    int ans = 0;
    priority_queue<Edge> que;
    for (int i = 0; i < m; i++) {
        if (check[i]) que.push(Edge(i, edges[i][0], edges[i][1], edges[i][2]));
    }
    while (!que.empty() && (u.cnt > 1)) {
        Edge temp = que.top();
        que.pop();
        if (u.merge(temp.from, temp.to)) {
            ans += temp.weight;
            indices.push_back(temp.ind);
        }
    }
    return u.cnt == 1 ? ans : -1;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    UnionSet u(n);
    int m = edges.size();
    vector<bool> check(m, true);
    vector<bool> appear(m, false);
    vector<int> indices;
    int mst_val = kruscal(u, edges, check, m, appear, indices);
    for (int &x : indices) appear[x] = true;
    vector<int> critical;
    vector<int> pseudo_critical;
    for (int i = 0; i < m; i++) {
        check[i] = false;
        u.clear();
        indices.clear();
        int t = kruscal(u, edges, check, m, appear, indices);
        u.clear();
        if (t == -1 || t > mst_val) critical.push_back(i); 
        else {
            if (t == mst_val) for (int &x : indices) appear[x] = true;
        }
        check[i] = true;
    }
    for (int &x : critical) appear[x] = false;
    for (int i = 0; i < m; i++) {
        if (appear[i]) pseudo_critical.push_back(i);
    }
    vector<vector<int>> res;
    res.push_back(critical);
    res.push_back(pseudo_critical);
    return res;
}

int main() {
    return 0;
}
