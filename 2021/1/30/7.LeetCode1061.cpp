/*************************************************************************
	> File Name: 7.LeetCode1061.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 02时01分04秒
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
        if (a < b) fa[b] = a;
        else fa[a] = b;
        n--;
    }
};

string smallestEquivalentString(string A, string B, string S) {
    UnionSet u(26);
    for (int i = 0; A[i]; i++) u.merge(A[i] - 'a', B[i] - 'a');
    for (int i = 0; S[i]; i++) S[i] = u.get(S[i] - 'a') + 'a';
    return S;
}

int main() {
    return 0;
}
