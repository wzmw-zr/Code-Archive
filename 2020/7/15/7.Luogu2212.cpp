/*************************************************************************
	> File Name: 7.Luogu2212.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 19时21分47秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX_N 2000

struct Node {
    int now, val;

    bool operator< (const Node &b) const {
        return this->val > b.val;
    }
};

int n, c;
int cnt, ans;
int xy[MAX_N + 5][2];
//int dis[MAX_N + 5];
int visit[MAX_N + 5];
priority_queue<Node> que;

int get_val(int x, int y) {
    return pow(xy[x][0] - xy[y][0], 2) + pow(xy[x][1] - xy[y][1], 2);
}

int main() {
    cin >> n >> c;
    //memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) cin >> xy[i][0] >> xy[i][1];
    que.push((Node) {1, 0});
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (visit[tmp.now]) continue;
        visit[tmp.now] = 1;
        ans += tmp.val;
        cnt++;
        if (cnt == n) break;
        for (int i = 1; i <= n; i++) {
            if (i == tmp.now || visit[i]) continue;
            int t = get_val(i, tmp.now);
            if (t < c) continue;
            que.push((Node) {i, t});
        }
    }
    if (cnt == n) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
