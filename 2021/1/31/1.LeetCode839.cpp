/*************************************************************************
	> File Name: 1.LeetCode839.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月31日 星期日 00时07分18秒
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

int numSimilarGroups(vector<string>& strs) {
    int ind = 0;
    int n = strs[0].size();
    unordered_map<string, int> mp;
    for (auto &x : strs) {
        if (mp.count(x)) continue;
        mp[x] = ind++;
    }
    UnionSet u(ind);
    for (auto &x : strs) {
        string temp = x;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(x[i], x[j]);
                if (mp.count(x)) u.merge(mp[temp], mp[x]);
                swap(x[i], x[j]);
            }
        }
    }
    return u.n;
}

int main() {
    return 0;
}
