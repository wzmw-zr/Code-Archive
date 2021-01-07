/*************************************************************************
	> File Name: 8.LeetCode737.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 09时10分15秒
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

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    if (words1.size() - words2.size()) return false;
    unordered_map<string, int> hash;
    int ind = 0;
    for (auto &s : words1) {
        if (!hash.count(s)) hash[s] = ind++;
    }
    for (auto &s : words2) {
        if (!hash.count(s)) hash[s] = ind++;
    }
    for (auto &x : pairs) {
        if (!hash.count(x[0])) hash[x[0]] = ind++;
        if (!hash.count(x[1])) hash[x[1]] = ind++;
    }
    UnionSet u(ind);
    for (auto &x : pairs) u.merge(hash[x[0]], hash[x[1]]);
    for (int i = 0; i < words1.size(); i++) {
        int ind_1 = u.get(hash[words1[i]]);
        int ind_2 = u.get(hash[words2[i]]);
        if (ind_1 - ind_2) return false;
    }
    return true;
}

int main() {
    return 0;
}
