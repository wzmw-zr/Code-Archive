/*************************************************************************
	> File Name: 7.Luogu1462.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月01日 星期三 20时43分30秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct edge {
    int to, val, next;
};

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

edge edg[100005];
int n, m, b, edg_cnt, cost[10005], head[10005], ans[10005];

void make_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int dijksta(int mmax) {
    memset(ans, 0x3f, sizeof(ans));
    priority_queue<node> que;
    que.push({1, 0});
    ans[1] = 0;
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (tmp.val > ans[tmp.now]) continue;
        for (int i = head[tmp.now]; i != -1; i = edg[i].next) {
            int to = edg[i].to, val = edg[i].val;
            if (cost[to] <= mmax && ans[to] > tmp.val + val)  {
                ans[to] = tmp.val + val;
                que.push({to, ans[to]});
            }
        }
    }
    if (ans[n] > b || ans[n] == 0x3f3f3f3f)  return 0;
    return 1;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
    int l = 0, r = 1000000000;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (dijksta(mid)) r = mid;
        else l = mid + 1;
    }
    if (l == 1000000000) cout << "AFK" << endl;
    else cout << l << endl;
    return 0;
}
