/*************************************************************************
	> File Name: 5.Luogu1265.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 18时18分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define MAX_N 5000

long n;
long xy[MAX_N + 5][2];
double dis[MAX_N + 5];
long visit[MAX_N + 5];

struct Node {
    long now;
    double val;

    bool operator< (const Node &b) const {
        return this->val > b.val;
    }
};

double distance(long a, long b) {
    long x = xy[a][0] - xy[b][0], y = xy[a][1] - xy[b][1];
    return sqrt(x * x + y * y);
}


int main() {
    cin >> n;
    for (int i = 0; i <= MAX_N + 5; i++) dis[i] = 99999999999;
    dis[1] = 0;
    double ans = 0;
    int cnt = 0;
    for (long i = 1; i <= n; i++) cin >> xy[i][0] >> xy[i][1];
    priority_queue<Node> que;
    que.push((Node) {1, 0});
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (visit[temp.now] == 1) continue;
        visit[temp.now] = 1;
        ans += temp.val;
        cnt++;
        if (cnt == n) break;
        for (long i = 1; i <= n; i++) {
            if (i == temp.now) continue;
            double t = distance(temp.now, i);
            if (t < dis[i]) {
                dis[i] = t;
                que.push((Node) {i, t});
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
