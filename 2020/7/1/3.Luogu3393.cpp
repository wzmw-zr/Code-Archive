/*************************************************************************
	> File Name: 3.Luogu3393.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月01日 星期三 18时24分10秒
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
#define MAX_N 100000
#define MAX_M 200000

struct edge {
    long to, next;
};

struct node {
    long now, val;
    bool operator< (const node &b) const{
        return this->val > b.val;
    }
};

struct sta {
    long now, left;
};

long n, m, k, s, p, q;
long head[MAX_N + 5], ans[MAX_N + 5], zombie[MAX_N + 5];
char status[MAX_N + 5];
long edge_cnt;

edge edg[2 * MAX_M + 5];

void make_edge(long a, long b) {
    edg[edge_cnt].to = b;
    edg[edge_cnt].next = head[a];
    head[a] = edge_cnt;
    edge_cnt++;
}

void init_status() {
    queue<sta> que;
    for (long i = 0; i < k; i++) {
        que.push((sta) {zombie[i], s});
        status[zombie[i]] = 0x3f;
    }
    while (!que.empty()) {
        sta tmp = que.front();
        que.pop();
        if (tmp.left == 0) continue;
        for (long i = head[tmp.now]; i != -1; i = edg[i].next) {
            if (status[edg[i].to] == 0) {
                status[edg[i].to] = 1;
                que.push((sta) {edg[i].to, tmp.left - 1});
            }
        }
    }
}

long dist(long x) {
    if (status[x] == 0) return p;
    else if (status[x] == 1) return q;
    return 0x3f3f3f3f3f3f3f3f;
}

void dijksta() {
    priority_queue<node> que;
    que.push((node) {1, 0});
    ans[1] = 0;
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (tmp.val > ans[tmp.now]) continue;
        for (long i = head[tmp.now]; i != -1; i = edg[i].next) {
            if (ans[edg[i].to] > ans[tmp.now] + dist(edg[i].to)) {
                ans[edg[i].to] = ans[tmp.now] + dist(edg[i].to);
                que.push((node) {edg[i].to, ans[edg[i].to]});
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> k >> s >> p >> q;
    for (long i = 0; i < k; i++) {
        cin >> zombie[i];
    }
    for (long i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        make_edge(a, b);
        make_edge(b, a);
    }
    init_status();
    dijksta();
    cout << ans[n] - dist(n) << endl;
    return 0;
}
