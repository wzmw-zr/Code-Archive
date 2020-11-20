/*************************************************************************
	> File Name: 3.LeetCode547.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月20日 星期五 13时06分25秒
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
    int cnt;
    vector<int> father;

    UnionSet() = default;
    UnionSet(int n) : n(n), cnt(n), father(n) {
        for (int i = 0; i < n; i++) father[i] = i;
    }

    int query(int x) { 
        return father[x] = (father[x] == x ? x : query(father[x]));
    }

    void merge(int x, int y) {
        int a = query(x), b = query(y);
        if (a == b) return ;
        father[a] = b;
        cnt--;
    }
};

int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    UnionSet u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!M[i][j]) continue;
            u.merge(i, j);
        }
    }
    return u.cnt;
}

int main() {
    return 0;
}
