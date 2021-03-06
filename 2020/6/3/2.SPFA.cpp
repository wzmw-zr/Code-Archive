/*************************************************************************
	> File Name: 2.SPFA.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月03日 星期三 18时53分23秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
#define MAX_N 10000
#define MAX_M 500000

struct Node {
    int e, dis, next;
};

int n, m, s, cnt, ans[MAX_N + 5], head[MAX_N + 5], que_mark[MAX_N + 5];
Node edge[MAX_M + 5];
char mark[MAX_N + 5][MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (mark[a][b]) {
            int ind = head[a];
            while (edge[ind].e != b) {
                ind = edge[ind].next;
            }
            edge[ind].dis = min(c, edge[ind].dis);
        } else {
            mark[a][b] = 1;
            edge[cnt].e = b;
            edge[cnt].dis = c;
            edge[cnt].next = head[a];
            head[a] = cnt;
            cnt++;
        }
    }
    ans[s] = 0;
    queue<int> que;
    que.push(s);
    que_mark[s] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0;
        for (int i = head[t]; i != -1; i = edge[i].next) {
            if (ans[edge[i].e] > ans[t] + edge[i].dis) {
                ans[edge[i].e] = ans[t] + edge[i].dis;
                if (!que_mark[edge[i].e]) {
                    que_mark[edge[i].e] = 1;
                    que.push(edge[i].e);
                }
            } 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3f3f3f3f) cout << ans[i];
        else cout << 0x7fffffff;
    }
    return 0;
}
