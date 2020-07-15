/*************************************************************************
	> File Name: 4.Luogu1265.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 18时06分31秒
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
#define MAX_N 5000

struct Pos {
    double x, y;
};

struct UnionSet {
    int fa[MAX_N + 5];   

    UnionSet() {
        for (int i = 0; i <= MAX_N + 5; i++) fa[i] = i;
    }
    
    int get(int x) {
        if (fa[x] == x) return x;
        return fa[x] = get(fa[x]);
    }

    void merge(int x, int y) {
        fa[get(x)] = get(y);
    }
};

struct Edge {
    int from, to;
    double dis;
};

int n;
Pos pos[MAX_N + 5];
Edge Edge[MAX_N * MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pos[i].x >> pos[i].y;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

        }
    }
    return 0;
}
