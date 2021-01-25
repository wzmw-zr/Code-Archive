/*************************************************************************
	> File Name: 1.LeetCode1128.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月26日 星期二 00时01分50秒
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
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[b] = a;
        cnt[a] += cnt[b];
    }
};

typedef pair<int, int> PII;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n = dominoes.size();
    UnionSet u(n);
    map<PII, int> mp;
    for (int i = 0; i < n; i++) {
        PII p_1(dominoes[i][0], dominoes[i][1]), p_2(dominoes[i][1], dominoes[i][0]);
        if (!mp.count(p_1) && !mp.count(p_2)) {
            mp[p_1] = i;
            continue;
        }
        if (mp.count(p_1)) u.merge(mp[p_1], i);
        if (mp.count(p_2)) u.merge(mp[p_2], i);
    }
    int ans = 0;
    unordered_set<int> handled;
    for (int i = 0; i < n; i++) {
        int fa = u.get(i);
        if (handled.count(fa)) continue;
        handled.insert(fa);
        int num = u.cnt[fa];
        if (num == 1) continue;
        ans += num * (num - 1) / 2;
    }
    return ans;
}

int main() {
    return 0;
}
