/*************************************************************************
	> File Name: 1.LeetCode1202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月11日 星期一 00时03分13秒
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
        for (int i = 0; i < n; i++) fa[i]= i;
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

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    string ans = s;
    vector<bool> check(n, false);
    UnionSet u(n);
    unordered_map<int, vector<int>> mp;
    for (auto &x : pairs) u.merge(x[0], x[1]);
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        int root = u.get(i);
        if (!mp.count(root)) mp[root] = vector<int>(0);
        mp[root].push_back(i);
    }
    auto cmp = [&](int x, int y){
        return s[x] < s[y];
    };
    for (auto &&[_, inds] : mp) {
        auto temp = inds;
        sort(temp.begin(), temp.end(), cmp);
        sort(inds.begin(), inds.end());
        int len = inds.size();
        for (int i = 0; i < len; i++) ans[inds[i]] = s[temp[i]];
    }
    return ans;
}

int main() {
    return 0;
}
