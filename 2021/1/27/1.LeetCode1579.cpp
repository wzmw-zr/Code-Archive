/*************************************************************************
	> File Name: 1.LeetCode1579.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月27日 星期三 00时09分52秒
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
    UnionSet(int n) : n(n), fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    int merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return 1;
        fa[a] = b;
        n--;
        return 0;
    }
};


int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    auto cmp = [](vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    };
    sort(edges.begin(), edges.end(), cmp); 
    UnionSet u1(n), u2(n);
    int ans = 0;
    for (auto &x : edges) {
        switch (x[0]) {
            case 1 : ans += u1.merge(x[1], x[2]); break;
            case 2 : ans += u2.merge(x[1], x[2]); break;
            case 3 : {
                int temp_1 = u1.merge(x[1], x[2]);
                int temp_2 = u2.merge(x[1], x[2]);
                ans += temp_1;
            } break;
        }
    }
    if (u1.n != 1 || u2.n != 1) return -1;
    return ans;
}

int main() {
    return 0;
}
