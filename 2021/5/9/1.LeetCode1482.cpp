/*************************************************************************
	> File Name: 1.LeetCode1482.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月09日 星期日 00时07分49秒
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
    int k;
    int num;
    vector<int> fa;
    vector<int> cnt;

    UnionSet() = default;
    UnionSet(int n, int k) : n(n), k(k), num(0), fa(n), cnt(n, 0) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    void set(int ind) {
        cnt[ind] = 1;
        if (k == 1) num++;
    }
    
    int find(int x) {
        return fa[x] = (x == fa[x] ? x : find(fa[x]));
    }

    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return ;
        fa[b] = a;
        num -= cnt[a] / k + cnt[b] / k;
        cnt[a] += cnt[b];
        num += cnt[a] / k;
    }
};

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (m * k > n) return -1;
    set<int> days;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        days.insert(bloomDay[i]);
        if (!mp.count(bloomDay[i])) mp[bloomDay[i]] = vector<int>(0);
        mp[bloomDay[i]].push_back(i);
    }
    UnionSet u(n, k);
    for (int d : days) {
        for (int ind : mp[d]) {
            u.set(ind);
            if (ind != 0) {
                if (u.cnt[ind - 1])
                   u.merge(ind - 1, ind); 
            }
            if (ind != (n - 1)) {
                if (u.cnt[ind + 1])
                    u.merge(ind, ind + 1);
            }
        }
        if (u.num >= m) return d;
    }
    return -1;
}

int main() {
    return 0;
}
