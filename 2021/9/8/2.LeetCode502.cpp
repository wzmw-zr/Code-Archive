/*************************************************************************
	> File Name: 2.LeetCode502.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月08日 星期三 14时55分53秒
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
    int profit;
    int capital;

    Node() = default;
    Node(int profit, int capital) : profit(profit), capital(capital) {}

    bool operator<(const struct Node &that) const {
        return this->capital == that.capital ? this->profit < that.profit : this->capital < that.capital;
    }
};

struct cmp {
    bool operator()(const Node &a, const Node &b) const {
        return a.profit < b.profit;
    }
};

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<Node> nodes;
    for (int i = 0; i < n; i++) nodes.push_back(move(Node(profits[i], capital[i])));
    sort(nodes.begin(), nodes.end());
    priority_queue<Node, vector<Node>, cmp> que;
    int ind = 0;
    while (k) {
        while (ind < n && w >= nodes[ind].capital) que.push(nodes[ind++]);
        if (que.empty()) break;
        w += que.top().profit;
        que.pop();
        k--;
    }
    return w;
}

int main() {
    return 0;
}
