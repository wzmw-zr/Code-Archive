/*************************************************************************
	> File Name: 2.b.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 14时02分00秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000

struct Node {
    int a, b, c;
};

int n, m;
Node arr[MAX_N + 5];

int cmp(Node a, Node b) {
    return a.c > b.c;
}

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];

    UnionSet() {
        for (int i = 0; i <= MAX_N; i++) fa[i] = i;
    }

    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }

    void merge(int a, int b) {
        int x = get(a), y = get(b);
        if (x == y) {
            return (val[a] - val[b] - t) % 2 == 0;
        }
        fa[x] = y;
        val[x] = (t + val[b] - val[a] + 2) % 2;
    }
};

UnionSet u;

int main() {
    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    sort(arr, arr + m, cmp);
    for (int i = 0; i < m; i++) {
        if ((u.get(arr[i].a) - u.get(arr[i].b)) u.merge(arr[i].a, arr[i].b);
        else {
            res = arr[i].c;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
