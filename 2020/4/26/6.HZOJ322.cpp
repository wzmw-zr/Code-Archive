/*************************************************************************
	> File Name: 6.HZOJ322.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月26日 星期日 22时31分27秒
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
#define MAX_N 1000000

long t, n;

struct Data {
    int x, y, e;
} arr[MAX_N + 5];

long fa[MAX_N + 5], val[MAX_N + 5];
map<long, long> ind;

void init(int n) {
    memset(arr, 0, sizeof(arr));
    memset(fa, 0, sizeof(fa));
    memset(val, 0, sizeof(val));
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 1;
    }
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] &= val[fa[x]];
    return fa[x] = root;
}

int merge(int x, int y, int e) {
    int a = get(x), b = get(y);
    if (a == b) {
        return (val[x] & val[y]) == e;
    }
    fa[a] = b;
    val[a] = val[x] & val[y] & e;
    return 1;
}


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ind.clear();
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> arr[j].x >> arr[j].y >> arr[j].e;
            ind[arr[j].x] = 0;
            ind[arr[j].y] = 0;
        }
        int cnt = 0;
        for (auto iter = ind.begin(); iter != ind.end(); iter++) {
            iter->second = (++cnt);
        }
        init(cnt);
        int flag = 0;
        for (int j = 1; j <= n; j++) {
            if (merge(ind[arr[j].x], ind[arr[j].y], arr[j].e)) continue;
            cout << "NO" << endl;
            flag = 1;
            break;
        }
        if (!flag) cout << "YES" << endl;
    }
    return 0;
}
