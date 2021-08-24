/*************************************************************************
	> File Name: 1.LeetCode787.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月24日 星期二 08时54分18秒
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

// WA
using PII = pair<int, int>;

struct Node {
    int ind;
    int val;
    int cnt;

    Node() = default;
    Node(int ind, int val, int cnt) : ind(ind), val(val), cnt(cnt) {}

    bool operator<(const struct Node &that) const {
        return this->cnt == that.cnt ? this->val > that.val : this->cnt > that.val;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<PII>> adj(n, vector<PII>(0));
    for (auto x : flights) adj[x[0]].push_back(PII(x[1], x[2]));
    priority_queue<Node> que;
    que.push(Node(src, 0, 1));
    int ans = INT32_MAX;
    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        if (temp.cnt > k + 2) break;
        if (temp.ind == dst) ans = min(ans, temp.val);
        for (auto x : adj[temp.ind]) que.push(Node(x.first, temp.val + x.second, temp.cnt + 1));
    }
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    return 0;
}
