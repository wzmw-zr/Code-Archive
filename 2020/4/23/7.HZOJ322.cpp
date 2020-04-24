/*************************************************************************
	> File Name: 7.HZOJ322.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月23日 星期四 23时13分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX_N 1000000

int t, n;
int x, y, e;
int fa[MAX_N + 5], val[MAX_N + 5];

void init() {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;
    }
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    if (val[x] + val[fa[x]] == 1) val[x] = 1;
    else val[x] = 0;
    return fa[x] = root;
}

int check(int i, int j, int e) {
    int a = get(i), b = get(j);
    if (a == b) {
        if (val[i] + val[j] + e == 1) return 0;
        return 1;
    }
    fa[a] = b;
    if (val[i] + val[j] + e == 1) val[a] = 1;
    else val[a] = 0;
    return 1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        int ans = 1;
        for (int i = 0; ans && i < n; i++) {
            cin >> x >> y >> e;
            ans &= check(x, y, e);
        }
        if (!ans) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
