/*************************************************************************
	> File Name: 6.Luogu1340.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 18时51分27秒
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
#define MAX_N 200
#define MAX_M 6000

struct Edge {
    int from, to, val, week;
};

bool cmp(Edge a, Edge b) {
    return a.val < b.val;
}

struct UnionSet {
    int fa[MAX_N + 5];

    UnionSet() {
        for (int i = 0; i <= MAX_N; i++) fa[i] = i;
    }

    int find_fa(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find_fa(fa[x]);
    }

    void init() {
        for (int i = 0; i <= MAX_N; i++) fa[i] = i;
    }

    void merge(int x, int y) {
        fa[x] = y;
    }
};

int n, m;
Edge edge[MAX_M + 5];

int main() {
    cin >> n >> m;
    UnionSet u;
    for (int i = 0; i < m; i++) {
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
        edge[i].week = i;
    }
    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; i++) {
        int ans = 0, cnt = 1;
        u.init();
        for (int j = 0; j < m; j++) {
            if (edge[j].week <= i) {
                int fa = u.find_fa(edge[j].from), fb = u.find_fa(edge[j].to);
                if (fa - fb) {
                    u.merge(fa, fb);
                    ans += edge[j].val;
                    cnt++;
                    if (cnt == n) break;
                }
            }
        }
        if (cnt == n) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
