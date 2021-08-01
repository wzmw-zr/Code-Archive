/*************************************************************************
	> File Name: 1.LeetCode743.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月02日 星期一 00时02分53秒
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
    int val;

    Node() = default;
    Node(int id, int val) : id(id), val(val) {}

    bool operator<(const struct Node &that) const {
        return this->val > that.val;
    }
};

using PII = pair<int, int>;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<PII>> graph(n + 1);
    for (auto t : times) graph[t[0]].push_back(PII(t[1], t[2]));
    unordered_map<int, int> mp;
    priority_queue<Node> que;
    que.push(Node(k, 0));
    int ans = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (mp.count(temp.id)) continue;
        mp[temp.id] = temp.val;
        n--;
        ans = temp.val;
        for (auto &&[v, w] : graph[temp.id]) {
            if (mp.count(v)) continue;
            que.push(Node(v, temp.val + w));
        }
    }
    return n ? -1 : ans;
}

int main() {
    return 0;
}
