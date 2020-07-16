/*************************************************************************
	> File Name: 1.LeetCode785.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月16日 星期四 07时08分20秒
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
#define MAX_N 100

struct UnionSet {
    int fa[MAX_N + 5];
    int val[MAX_N + 5];

    UnionSet() {
        for (int i = 0; i <= MAX_N; i++) fa[i] = i, val[i] = 0;
    }
    
    int get(int x) {
        if (x == fa[x]) return x;
        val[x] += val[fa[x]];
        val[x] = (val[x] + 2) % 2;
        fa[x] = get(fa[x]);
        return fa[x];
    }

    void merge(int x, int y) {
        fa[x] = y;
        val[x] = 1;
    }

    int in_same_set(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a - b) return 0;
        if ((val[x] - val[y] + 2) % 2) return 0;
        return 1;
    }
};

bool isBipartite(vector<vector<int>> &graph) {
    UnionSet u;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (u.in_same_set(graph[i][j], i)) return false;
            u.merge(graph[i][j], i);
        }
    }
    return true;
}

int main() {
    return 0;
}
