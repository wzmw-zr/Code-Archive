/*************************************************************************
	> File Name: 4.LeetCode5870.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月12日 星期日 11时07分53秒
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

using PII = pair<int, int>;

struct Node {
    int ind;
    int out_degree;
    set<PII> intervals;

    Node() = default;
    Node(int ind, int num) : ind(ind), out_degree(0), intervals(set<PII>({PII(num, num)})) {}
};

set<PII> merge(set<PII> &intervals) {
    set<PII> ans;
    for (auto &&interval : intervals) {
        if (ans.empty() || ans.begin()->second < interval.first - 1) {
            ans.insert(move(interval));
            continue;
        }
        auto [l, r] = *ans.rbegin();
        ans.erase(prev(ans.end()));
        r = max(r, interval.second);
        ans.insert(PII(l, r));
    }
    return ans;
}

vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = parents.size();
    vector<Node> nodes;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) nodes.push_back(Node(i, nums[i]));
    for (int i = 1; i < n; i++) nodes[parents[i]].out_degree++;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (nodes[i].out_degree) continue;
        que.push(i);
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop();
        nodes[ind].intervals = merge(nodes[ind].intervals);
        ans[ind] = nodes[ind].intervals.begin()->first > 1 ? 1 : nodes[ind].intervals.begin()->second + 1;
        if (ind) {
            for (auto &&inter : nodes[ind].intervals) nodes[parents[ind]].intervals.insert(move(inter));
            if (!(--nodes[parents[ind]].out_degree)) que.push(parents[ind]);
        }
    }
    return ans;
}

int main() {
    return 0;
}
