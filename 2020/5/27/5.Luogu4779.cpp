/*************************************************************************
	> File Name: 5.Luogu4779.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月27日 星期三 20时24分20秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_N 100000
#define MAX_M 200000

struct node {
    int e, dis, next;
};

struct point {
    int now, dist;
    bool operator< (const point &b) const{
        return this->dist > b.dist;
    }
};

int n, m, s, ans[MAX_N + 5], head[MAX_N + 5];
node edge[MAX_M + 5];


int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].e = b;
        edge[i].dis = c;
        edge[i].next = head[a];
        head[a] = i;
    }
    priority_queue<point> que;
    que.push({s, 0});
    while (!que.empty()) {
        point t = que.top();
        que.pop();
        if (ans[t.now] != 0x3f3f3f3f) continue;
        ans[t.now] = t.dist;
        for (int i = head[t.now]; i != -1; i = edge[i].next) {
            que.push({edge[i].e, t.dist + edge[i].dis});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    return 0;
}
