/*************************************************************************
	> File Name: 2.LeetCode347.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月10日 星期四 00时11分19秒
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
    int val;
    int cnt;

    Node() = default;
    Node(int val, int cnt) : val(val), cnt(cnt) {}

    bool operator<(const struct Node &that) const {
        return this->cnt < that.cnt;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    vector<Node> nodes;
    for (auto &&[val, cnt] : mp) nodes.push_back(Node(val, cnt));
    sort(nodes.begin(), nodes.end());
    vector<int> ans;
    int n = nodes.size();
    for (int i = 1; i <= k; i++) ans.push_back(nodes[n - i].val);
    return ans;
}

int main() {
    return 0;
}
