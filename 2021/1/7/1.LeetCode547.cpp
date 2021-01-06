/*************************************************************************
	> File Name: 1.LeetCode547.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 00时02分28秒
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
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
        cnt--;
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionSet u(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j]) u.merge(i, j);
        }
    }
    return u.cnt;
}

int main() {
    return 0;
}
