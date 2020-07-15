/*************************************************************************
	> File Name: 9.Luogu4826.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 20时26分43秒
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
#define MAX_N 2000

struct Unionset {
    long fa[MAX_N + 5];

    Unionset() {
        for (long i = 0; i <= MAX_N; i++) fa[i] = i;
    }

    long get(long x) {
        if (x == fa[x]) return x;
        return fa[x] = get(fa[x]);
    }

    void merge(long x, long y) {
        fa[x] = y;
    }
};

struct Edge {
    long from, to, val;
};

long n;
long ans, cnt;
long edge_cnt;
long id[MAX_N + 5];
Edge edge[2 * MAX_N * MAX_N + 5];

long cmp(Edge a, Edge b) {
    return a.val > b.val;
}

int main() {
    Unionset u;

    cin >> n;
    for (long i = 0; i < n; i++) cin >> id[i];
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            if (i == j) continue;
            edge[edge_cnt].from = i;
            edge[edge_cnt].to = j;
            edge[edge_cnt].val = id[i] ^ id[j];
            edge_cnt++;
        }
    }
    sort(edge, edge + edge_cnt, cmp);
    for (long i = 0; i < edge_cnt && cnt < n; i++) {
        long a = u.get(edge[i].from), b = u.get(edge[i].to);
        if (a == b) continue;
        u.merge(a, b);
        ans += edge[i].val;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
