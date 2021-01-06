/*************************************************************************
	> File Name: 2.LeetCode787.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月06日 星期三 08时25分44秒
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
    int to;
    int cost;
    Edge() = default;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

struct Node {
    int ind;
    int cost;
    int step;
    Node() = default;
    Node(int ind, int cost, int step) : ind(ind), cost(cost), step(step) {}
    bool operator<(const struct Node &a) const {
        return this->cost > a.cost;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<Edge>> graph(n, vector<Edge>(0));
    for (auto &x : flights) graph[x[0]].push_back(Edge(x[1], x[2]));
    priority_queue<Node> que;
    que.push(Node(src, 0, -1));
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.step > K) continue;
        if (temp.ind == src && temp.step <= K) return temp.cost; 
        for (auto &x : graph[temp.ind]) que.push(Node(x.to, temp.cost + x.cost, temp.step + 1));
    }
    return -1;
}

int main() {
    return 0;
}
