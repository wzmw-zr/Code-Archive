/*************************************************************************
	> File Name: 2.LeetCode743.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月27日 星期日 08时56分09秒
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
    int to, val;
    Edge() = default;
    Edge(int to, int val) : to(to), val(val) {}
};

struct Node {
    int ind;
    vector<Edge> edges;
    Node() = default;
    Node(int ind) : ind(ind) {}
};

struct Point {
    int ind;
    int times;
    Point() = default;
    Point(int ind, int times) : ind(ind), times(times) {}
    bool operator<(const struct Point &a) const {
        return this->times > a.times;
    }
};

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<Node> nodes(N + 1);
    vector<int> check(N + 1, 0);
    int ans = 0;
    for (int i = 0; i < N; i++) nodes[i].ind = i + 1;
    for (auto &x : times) nodes[x[0]].edges.push_back(Edge(x[1], x[2]));
    priority_queue<Point> que;
    que.push(Point(K, 0));
    while (!que.empty()) {
        Point temp = que.top();
        que.pop();
        if (check[temp.ind]) continue;
        check[temp.ind] = 1;
        N--;
        ans = max(ans, temp.times);
        for (auto &x : nodes[temp.ind].edges) {
            if (check[x.to]) continue;
            que.push(Point(x.to, temp.times + x.val));
        }
    }
    if (N) return -1;
    return ans;
}

int main() {
    return 0;
}
