/*************************************************************************
	> File Name: 6.Luogu2829.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月01日 星期三 20时08分55秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX_N 5000
#define MAX_M 100000

struct edge {
    int from, to, val, next;
};

struct Node {
    int now, val;

    bool operator< (const Node &b) const {
        return this->val > b.val;
    };
};

int n, m, k, edge_cnt;
int head[MAX_N + 5], degree[MAX_N + 5], ans1[MAX_N + 5], ans2[MAX_N + 5];
edge edg[2 * MAX_M + 5];

void add_edge(int u, int v, int w) {
    edg[edge_cnt].from = u;
    edg[edge_cnt].to = v;
    edg[edge_cnt].val = w;
    edg[edge_cnt].next = head[u];
    head[u] = edge_cnt;
    edge_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans1, 0x3f, sizeof(ans1));
    memset(ans2, 0x3f, sizeof(ans2));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    priority_queue<Node> que;
    que.push({1, 0});
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        ans1[tmp.now] = min(ans1[tmp.now], tmp.val);
        for (int i = head[tmp.now]; i != -1; i = edg[i].next) {
            if (ans1[edg[i].to] > ans1[tmp.now] + edg[i].val) {
                ans1[edg[i].to] = ans1[tmp.now] + edg[i].val;
                que.push({edg[i].to, ans1[edg[i].to]});
            }
        }
    }

    que.push({n, 0});
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        ans2[tmp.now] = min(ans2[tmp.now], tmp.val);
        for (int i = head[tmp.now]; i != -1; i = edg[i].next) {
            if (ans2[edg[i].to] > ans2[tmp.now] + edg[i].val) {
                ans2[edg[i].to] = ans2[tmp.now] + edg[i].val;
                que.push({edg[i].to, ans2[edg[i].to]});
            }
        }
    }

    int fin = 0x3f3f3f3f;
    for (int i = 0; i < edge_cnt; i++) {
        if (ans1[edg[i].from] + ans2[edg[i].to] + edg[i].val == ans1[n]) 
            continue;
        fin = min(fin, ans1[edg[i].from] + ans2[edg[i].to] + edg[i].val);
    }
    cout << fin << endl;
    return 0;
}
