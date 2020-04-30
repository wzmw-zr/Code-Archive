/*************************************************************************
	> File Name: 13.HZOJ324.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 23时22分25秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
#define MAX_N 500000

int n;
int fa[MAX_N + 5], val[MAX_N + 5], tail[MAX_N + 5];

void init() {
    for (int i = 0; i <= n; i++) fa[i] = i, val[i] = 1, tail[i] = i;
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] = val[fa[x]] + 1;
    return fa[x] = root;
}

void merge(int x, int y) {
    int a = get(x), b = get(y);
    if (a == b) return ;
    fa[a] = tail[b];
    val[a] = val[fa[a]] + 1;
    tail[b] = tail[a];
}

int query(int x, int y) {
    int a = get(x), b = get(y);
    cout << "x = " << x << ", y = " << y << endl;
    cout << val[x] << " " << val[y] << endl;
    if (a == b) return abs(val[x] - val[y]) - 1; 
    return -1;
}

int main() {
    cin >> n;
    init();
    char t;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> t >> x >> y;
        if (t == 'M') merge(x, y);
        else {
            if (x == y) cout << 0 << endl;
            else cout << query(x, y) << endl;
        }
    }
    return 0;
}
