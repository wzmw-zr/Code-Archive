/*************************************************************************
	> File Name: 2.LeetCode1857.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月11日 星期二 00时56分29秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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
    int ind;
    int in_degree;
    char color;
    vector<int> colors;
    vector<int> to;

    Node() : in_degree(0), colors(26, 0) {}
    Node(int ind, char color) : ind(ind), in_degree(0), color(color), colors(26, 0) {}
};

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    int m = edges.size();
    vector<Node *> nodes(n, nullptr);
    for (int i = 0; i < n; i++) 
        nodes[i] = new Node(i, colors[i]);
    for (int i = 0; i < m; i++) {
        nodes[edges[i][0]]->to.push_back(edges[i][1]);
        nodes[edges[i][1]]->in_degree++;
    }
    int cnt = n;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (nodes[i]->in_degree) continue;
        que.push(i);
        cnt--;
    }
    int ans = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        nodes[temp]->colors[nodes[temp]->color - 'a']++;
        for (int x : nodes[temp]->colors)
            ans = max(ans, x);
        for (int x : nodes[temp]->to) {
            for (int i = 0; i < 26; i++) {
                nodes[x]->colors[i] = max(nodes[x]->colors[i], nodes[temp]->colors[i]);
            }
            if (!(--nodes[x]->in_degree)) {
                que.push(x);
                cnt--;
            }
        }
    }
    return cnt == 0 ? ans : -1;
}

int main() {
    return 0;
}
