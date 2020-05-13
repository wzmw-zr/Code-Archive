/*************************************************************************
	> File Name: 2.HZOJ506.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月13日 星期三 18时08分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 30

struct Node {
    int ind, t;
};

int n;
Node a[MAX_N + 5];

int cmp(Node a, Node b) {
    return a.t < b.t;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].ind = i;
        cin >> a[i].t;
    }
    sort(a + 1, a + n + 1, cmp);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i - 1) {
            printf(" ");
            res += a[i - 1].t;
            a[i].t += a[i - 1].t;
        }
        printf("%d", a[i].ind);
    }
    double val = (res * 1.0) / (n * 1.0);
    printf("\n%.2lf\n", val);
    return 0;
}
