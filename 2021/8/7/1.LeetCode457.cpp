/*************************************************************************
	> File Name: 1.LeetCode457.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月07日 星期六 00时12分38秒
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
    int next;
    int in_degree;
    Node() : next(0), in_degree(0) {}
};

bool is_circle(vector<int> &nums, vector<Node> &nodes, vector<int> &check, int start) {
    int cnt = 1;
    int flag = nums[start] > 0 ? 1 : -1;
    bool ans = true;
    check[start] = 1;
    int p = nodes[start].next;
    while (p != start) {
        check[p] = 1;
        if (nums[p] > 0) {
            if (flag == -1) ans = false;
        } else {
            if (flag == 1) ans = false;
        }
        p = nodes[p].next;
        cnt++;
    }
    return ans ? (cnt > 1) : ans;
}

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        int t = (i + (nums[i] % n) + n) % n;
        nodes[i].next = t;
        nodes[t].in_degree++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (nodes[i].in_degree) continue;
        que.push(i);
    }
    vector<int> check(n, 0);
    while (!que.empty()) {
        int t = que.front();
        check[t] = 1;
        que.pop();
        if (!(--nodes[nodes[t].next].in_degree)) que.push(nodes[t].next);
    }
    for (int i = 0; i < n; i++) {
        if (!nodes[i].in_degree || check[i]) continue;
        if (is_circle(nums, nodes, check, i)) return true;
    }
    return false;
}

int main() {
    return 0;
}
