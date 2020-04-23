/*************************************************************************
	> File Name: 4.HAOJ326.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月23日 星期四 20时08分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 50000

int n, k, ans;
int fa[MAX_N + 5], val[MAX_N + 5];
int d, x, y;

void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;
    }
}

int get(int x) {
   if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 3;
    return fa[x] = root;
}

int merge(int x, int y, int t) {
    int a = get(x), b = get(y);
    if (t == 1 && x == y) return 0; 
    if (a == b) {
        return (val[x] - val[y] - t) % 3 == 0;
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 3) % 3;
    return 1;
}

int main() {
    cin >> n >> k;
    init();
    for (int i = 0; i < k; i++) {
        cin >> d >> x >> y;
        d -= 1;
        if (x <= n && y <= n && merge(x, y, d)) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
