/*************************************************************************
	> File Name: 2.LeetCode5650.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月11日 星期一 00时38分02秒
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
    }
};

int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int n = source.size();
    int ans = 0;
    UnionSet u(n);
    for (auto &x : allowedSwaps) u.merge(x[0], x[1]);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int root = u.get(i);
        if (!mp.count(root)) mp[root] = vector<int>(0);
        mp[root].push_back(i);
    }
    for (auto &&[_, inds] : mp) {
        unordered_map<int, int> cnt;
        for (int &x : inds) cnt[source[x]]++;
        for (int &x : inds) {
            if (!cnt.count(target[x]) || !cnt[target[x]]) {
                ans++;
                continue;
            }
            cnt[target[x]]--;
        }
    }
    return ans;
}

int main() {
    return 0;
}
