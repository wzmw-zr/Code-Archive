/*************************************************************************
	> File Name: 1.LeetCode323.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月13日 星期日 07时57分08秒
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
    int cnt;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : cnt(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    } 

    int get(int a) {
        return fa[a] == a ? a : (fa[a] = get(fa[a]));
    }

    void merge(int a, int b) {
        int x = get(a);
        int y = get(b);
        if (x == y) return ;
        fa[x] = y;
        cnt--;
    }
};

int countComponents(int n, vector<vector<int>>& edges) {
    UnionSet u(n);
    for (auto &x : edges) u.merge(x[0], x[1]);
    return u.cnt;
}

int main() {
    return 0;
}
