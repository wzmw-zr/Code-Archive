/*************************************************************************
	> File Name: 1.LeetCode684.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月13日 星期三 00时03分38秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct UnionSet {
    int n;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    bool merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return false;
        fa[a] = b;
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionSet u(n + 1);
    for (auto &x : edges) {
        if (u.merge(x[0], x[1])) continue;
        return x;
    }
    return vector<int>(0);
}

int main() {
    return 0;
}
