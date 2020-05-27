/*************************************************************************
	> File Name: 4.Lougu3371.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月27日 星期三 19时25分06秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_N 10000
#define MAX_M 500000

struct node {
    int e, dis, next;
};

struct point {
    int now, dist;
    bool operator< (const point &b) const{
        return this->dist > b.dist;
    }
};

int n, m, s, cnt, ans[MAX_N + 5], head[MAX_N + 5];
node edge[MAX_M + 5];
int mark[MAX_N + 5][MAX_N + 5];


int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (mark[a][b]) {
            int ind = head[a];
            while (edge[ind].next != b) {
                ind = edge[ind].next;
            }
            edge[ind].dis = min(edge[ind].dis, c);
            continue;
        }
        edge[cnt].e = b;
        edge[cnt].dis = c;
        edge[cnt].next = head[a];
        head[a] = cnt;
        cnt++;
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
        if (ans[i] != 0x3f3f3f3f) cout << ans[i];
        else cout << 0x7fffffff;
    }
    return 0;
}
