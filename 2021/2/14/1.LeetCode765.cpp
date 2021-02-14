/*************************************************************************
	> File Name: 1.LeetCode765.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月14日 星期日 08时32分00秒
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
    vector<int> cnt;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n), cnt(n, 1) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int find(int x) {
        return fa[x] = (x == fa[x] ? x : find(fa[x]));
    }
    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return ;
        fa[a] = b;
        cnt[b] += cnt[a];
    }
};

int minSwapsCouples(vector<int>& row) {
    int n = row.size(), ans = 0;
    UnionSet u(n / 2);
    for (int i = 0; i < n; i += 2) u.merge(row[i] / 2, row[i + 1] / 2);
    unordered_set<int> st;
    for (int i = 0; i < n / 2; i++) st.insert(u.find(i));
    for (int x : st) ans += u.cnt[x] - 1;
    return ans;
}

int main() {
    return 0;
}
