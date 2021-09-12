/*************************************************************************
	> File Name: 3.LeetCode5870.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月12日 星期日 10时46分05秒
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
    int ind;
    vector<Node *> children;

    Node() = default;
    Node(int ind) : ind(ind), children(vector<Node *>(0)) {}
};

using PII = pair<int, int>;

set<PII> dfs(Node *root, vector<int> &nums, vector<int> &ans) {
    if (!root) return set<PII>({});
    set<PII> res, ret;
    res.insert(PII(nums[root->ind], nums[root->ind]));
    for (auto child : root->children) {
        auto temp = dfs(child, nums, ans);
        for (auto &&t : temp) res.insert(move(t));
    }
    for (auto &&interval : res) {
        if (ret.empty() || ret.rbegin()->second < interval.first - 1) {
            ret.insert(move(interval));
            continue;
        }
        auto [l, r] = *ret.rbegin();
        ret.erase(prev(ret.end()));
        r = max(r, interval.second);
        ret.insert(PII(l, r));
    }
    ans[root->ind] = ret.begin()->first > 1 ? 1 : ret.begin()->second + 1;
    return ret;
}

vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = parents.size();
    vector<Node *> nodes(n, nullptr);
    for (int i = 0; i < n; i++) nodes[i] = new Node(i);
    for (int i = 1; i < n; i++) nodes[parents[i]]->children.push_back(nodes[i]);
    vector<int> ans(n);
    dfs(nodes[0], nums, ans);
    return ans;
}

int main() {
    return 0;
}
