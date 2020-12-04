/*************************************************************************
	> File Name: 2.LeetCode1135.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月04日 星期五 20时30分26秒
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
    int cost;
    int start, end;
    Edge() = default;
    Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {};
    bool operator<(const struct Edge &a) const {
        return this->cost > a.cost;
    }
};

struct UnionSet {
    vector<int> fa;   
    int cnt;
    UnionSet() = default;
    UnionSet(int n) : fa(n + 1, 0), cnt(n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return x == fa[x] ? x : fa[x] = get(fa[x]);
    }
    bool merge(int a, int b) {
        int x = get(a);
        int y = get(b);
        if (x == y) return false;
        fa[x] = y;
        cnt--;
        return true;
    }
};

int minimumCost(int N, vector<vector<int>>& connections) {
    UnionSet u(N);
    priority_queue<Edge> que;
    for (auto &x : connections) {
        que.push({x[0], x[1], x[2]});
        que.push({x[1], x[0], x[2]});
    }
    int ans = 0;
    while (!que.empty()) {
        Edge temp = que.top();
        que.pop();
        if (!u.merge(temp.start, temp.end)) continue;
        ans += temp.cost;
    }
    if (u.cnt == 1) return ans;
    return -1;
}

int main() {
    return 0;
}
