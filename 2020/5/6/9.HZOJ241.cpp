/*************************************************************************
	> File Name: 8.HZOJ241.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 19时22分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 100000

struct Node {
    double x, y;
    int z;
};

int n, px[2 * MAX_N + 5], px_ind;
Node p[2 * MAX_N + 5];

int cmp(Node a, Node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int cmp2(int a, int b) {
    return p[px[a]].y < p[px[b]] < y;
}

double dis(int l, int r) {
    return sqrt(pow(p[l].x - p[r].x, 2) + pow(p[l].y - p[r].y, 2));
}

double func(int l, int r) {
    if (l == r) return 2100000000;
    if (l + 1 == r) {
        if (p[l].z != p[r].z) return dis(l, r);
        return 2100000000;
    }
    int mid = (l + r) / 2;
    double d = min(func(l, mid), func(mid + 1, r));
    int raw = px_ind;
    for (int i = mid; i >= l && p[mid].x - p[i].x < d; i--) {
        px[px_ind++] = i;
    }
    for (int j = mid + 1; j < r && p[j].x - p[mid].x < d; j++) {
        px[px_ind++] = j;
    }
    sort(px + raw, px + px_ind, cmp2);
    for (int i = raw; i < px_ind; i++) {
        for (int j = i + 1; j < px_ind && p[px[j]].y - p[px[i]].y < d; j++) {
            if (p[px[i]].z != p[px[j]].z) d = min(d, dis(px[i], px[j]))
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 1;
    }
    for (int i = 2 * n - 1; i >= n; i--) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 0;
    }
    sort(p, p + 2 * n, cmp);
    double ans = func(0, 2 * n - 1);
    printf("%.3lf\n", ans);
    return 0;
}
