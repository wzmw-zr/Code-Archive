/*************************************************************************
	> File Name: 5.HZOJ72.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月27日 星期一 21时30分21秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
#define MAX_N 10000

int fa[MAX_N + 5], val[MAX_N + 5];

void init(int n) {
    for (int i = 0; i <= n; i++) fa[i] = i; 
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 3;
    return fa[x] = root;
}

void merge(int x, int y) {
    int a = get(x), b = get(y);
    if (a == b) return ;
    fa[a] = b;
    val[a] = (val[y] + 1 - val[x] + 3) % 3;
}

int query(int x, int y) {
    int a = get(x), b = get(y);
    if (a != b) return -1;
    return (val[x] - val[y] + 3) % 3;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        if (a == 1) merge(b, c);
        else {
            switch (query(b, c)) {
                case -1 : cout << "Unknown" << endl; break;
                case 0 : cout << "Tie" << endl; break;
                case 1 : cout << "Win" << endl; break;
                case 2 : cout << "Loss" << endl; break;
            }
        }
    }
    return 0;
}
