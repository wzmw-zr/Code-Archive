/*************************************************************************
	> File Name: 1.LeetCode1924.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月01日 星期四 00时02分50秒
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
    int step;

    Node() = default;
    Node(int ind, int step) : ind(ind), step(step) {}
};

ostream &operator<<(ostream &out, struct Node &node) {
    out << "(" << node.ind << "," << node.step << ")";
    return out;
}

int numWays(int n, vector<vector<int>>& relation, int k) {
    unordered_map<int, unordered_set<int>> mp;
    for (auto &r : relation) {
        if (!mp.count(r[0])) mp[r[0]] = unordered_set<int>();
        mp[r[0]].insert(r[1]);
    }
    queue<Node> que;
    que.push(Node(0, 0));
    int ans = 0;
    while (!que.empty()) {
        auto temp = que.front();
        que.pop();
        if (temp.step == k) {
            if (temp.ind == (n - 1)) ans++;
            continue;
        }
        if (!mp.count(temp.ind)) continue;
        for (auto &x : mp[temp.ind]) que.push(Node(x, temp.step + 1));
    }
    return ans;
}

int main() {
    return 0;
}
