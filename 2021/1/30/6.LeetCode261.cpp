/*************************************************************************
	> File Name: 6.LeetCode261.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 01时54分32秒
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
        n--;
        return true;
    }
};

bool validTree(int n, vector<vector<int>>& edges) {
    UnionSet u(n);
    for (auto &x : edges) {
        if (u.merge(x[0], x[1])) continue;
        return false;
    }
    return u.n == 1;
}

int main() {
    return 0;
}
