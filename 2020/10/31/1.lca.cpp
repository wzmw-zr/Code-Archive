/*************************************************************************
	> File Name: 1.lca.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月31日 星期六 09时18分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 10000

vector<int> v[MAX_N + 10];

int fa[MAX_N + 10][31];
int dep[MAX_N + 10];

int n, m;
int a, b;

void dfs(int root, int fa_no) {
    fa[root][0] = fa_no;
    dep[root] = dep[fa[root][0]] + 1;
    for (int i = 1; i < 31; i++) {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    int sz = v[root].size();
    for (int i = 0; i < sz; i++) {
        if (v[root][i] == fa_no) continue;
        dfs(v[root][i], root);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int temp = dep[y] - dep[x];
    for (int i = 0; temp; i++, temp >>= 1) {
        if (temp & 1) y = fa[y][i];
    }
    if (y == x) return x;
    for (int i = 30; i >= 0 && y != x; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return x;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a++, b++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    cin >> n;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a++, b++;
        cout << lca(a, b) << endl;
    }
    return 0;
}
