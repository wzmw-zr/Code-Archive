/*************************************************************************
	> File Name: 5.LeetCode1101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 01时47分17秒
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
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
        n--;
    }
};

int earliestAcq(vector<vector<int>>& logs, int N) {
    UnionSet u(N);
    sort(logs.begin(), logs.end());
    int ans = 0;
    for (auto &x : logs) {
        ans = x[0];
        u.merge(x[1], x[2]);
        if (u.n == 1) break;
    }
    return u.n == 1 ? ans : -1;
}

int main() {
    return 0;
}
