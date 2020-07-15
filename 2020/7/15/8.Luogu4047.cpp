/*************************************************************************
	> File Name: 8.Luogu4047.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 19时51分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX_N 1000
#define MAX_K 1000

struct Unionset {
    int fa[MAX_N + 5];
    int cnt;
    
    Unionset(int  n) {
        for (int i = 0; i <= MAX_N; i++) fa[i] = i;
        cnt = n;
    }

    void init() {
        for (int i = 0; i <= MAX_N; i++) fa[i] = i;
    }

    int get(int x) {
        if (fa[x] == x) return x;
        return fa[x] = get(fa[x]);
    }

    void merge(int x, int y) {
        fa[x] = y;
        cnt--;
    }
};

struct Edge {
    int from, to;
    double val;
};

int n, k;
int xy[MAX_N + 5][2];
Edge edge[2 * MAX_N * MAX_N + 5];

double get_dis(int a, int b) {
    int x = xy[a][0] - xy[b][0];
    int y = xy[a][1] - xy[b][1];
    return sqrt(x * x + y * y);
}

int cmp(Edge a, Edge b) {
    return a.val < b.val;
}

int main() {
    cin >> n >> k;
    Unionset u(n);
    int edge_cnt = 0;
    for (int i = 0; i < n; i++) cin >> xy[i][0] >> xy[i][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double dis = get_dis(i, j);
            edge[edge_cnt].from = i;
            edge[edge_cnt].to = j;
            edge[edge_cnt].val = dis;
            edge_cnt++;
        }
    }
    sort(edge, edge + edge_cnt, cmp);
    int i;
    for (i = 0; u.cnt != k; i++) {
        int a = u.get(edge[i].from), b = u.get(edge[i].to);
        if (a == b) continue;
        u.merge(a, b);
    }
    for (; i < edge_cnt; i++) {
        int a = u.get(edge[i].from), b = u.get(edge[i].to);
        if (a == b) continue;
        printf("%.2f\n", edge[i].val);
        break;
    }
    return 0;
}
