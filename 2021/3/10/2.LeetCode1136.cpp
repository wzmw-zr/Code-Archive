/*************************************************************************
	> File Name: 2.LeetCode1136.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月10日 星期三 22时26分48秒
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

struct Node {
    int in_degree;
    int stage;
    vector<int> to;
    Node() : in_degree(0), stage(0) {}
};

int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<Node> nodes(n + 1);
    for (auto &r : relations) {
        nodes[r[0]].to.push_back(r[1]);
        nodes[r[1]].in_degree++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (nodes[i].in_degree) continue;
        nodes[i].stage = 1;
        que.push(i);
    }
    int ans = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        n--;
        ans = max(ans, nodes[t].stage);
        for (int &ind : nodes[t].to) {
            if (!(--nodes[ind].in_degree)) {
                nodes[ind].stage = nodes[t].stage + 1;
                que.push(ind);
            }
        }
    }
    return n == 0 ? ans : -1;
}

int main() {
    return 0;
}
