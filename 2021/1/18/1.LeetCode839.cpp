/*************************************************************************
	> File Name: 1.LeetCode839.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月18日 星期一 20时12分57秒
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

bool check(string &s1, string &s2) {
    int cnt = 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[i]) continue;
        cnt++;
        if (cnt > 2) return false;
    }
    return true;
}

int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    UnionSet u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!check(strs[i], strs[j])) continue;
            u.merge(i, j);
        }
    }
    return u.n;
}

int main() {
    return 0;
}
