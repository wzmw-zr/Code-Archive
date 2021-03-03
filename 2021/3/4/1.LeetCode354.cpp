/*************************************************************************
	> File Name: 1.LeetCode354.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月04日 星期四 00时29分49秒
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
    int x, y;
    int degree;
    int cnt;
    vector<Node *> next;
    Node() = default;
    Node(int x, int y) : x(x), y(y), degree(0), cnt(1) {}
};

int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end());
    vector<Node *> nodes(n, nullptr);
    for (int i = 0; i < n; i++) nodes[i] = new Node(envelopes[i][0], envelopes[i][1]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[j]->x > nodes[i]->x && nodes[j]->y > nodes[i]->y) {
                nodes[j]->degree++;
                nodes[i]->next.push_back(nodes[j]);
            }
        }
    }
    queue<Node *> que;
    for (int i = 0; i < n; i++) {
        if (nodes[i]->degree) continue;
        que.push(nodes[i]);
    }
    int ans = 0;
    while (!que.empty()) {
        Node *temp = que.front();
        ans = max(ans, temp->cnt);
        que.pop();
        for (Node *p : temp->next) {
            if (!(--p->degree)) que.push(p);
            p->cnt = max(p->cnt, temp->cnt + 1);
        }
    }
    for (int i = 0; i < n; i++) delete nodes[i];
    return ans;
}

int main() {
    return 0;
}
