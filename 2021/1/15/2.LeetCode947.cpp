/*************************************************************************
	> File Name: 2.LeetCode947.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月15日 星期五 00时56分26秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<queue>
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
        this->n--;
        fa[a] = b;
    }
};

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    UnionSet u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) u.merge(i, j);
        }
    }
    return u.n;
}

int main() {
    return 0;
}
