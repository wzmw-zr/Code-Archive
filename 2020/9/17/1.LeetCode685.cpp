/*************************************************************************
	> File Name: 1.LeetCode685.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月17日 星期四 07时53分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

struct UnionSet {
    vector<int> fa;

    UnionSet() = default;

    UnionSet(int n) {
        for (int i = 0; i <= n + 5; i++) fa.push_back(i);
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int x_t = find(x);
        int y_t = find(y);
        if (x_t - y_t) return false;
        fa[x_t] = y_t;
        return true;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    UnionSet u(edges.size());
    for (auto &x : edges) {
        if (!u.merge(x[0], x[1])) return x;
        continue;
    }
    return vector<int>(0, 0);
}

int main() {
    return 0;
}
