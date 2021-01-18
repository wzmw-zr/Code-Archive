/*************************************************************************
	> File Name: 4.LeetCode305.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月18日 星期一 21时42分40秒
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
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

#define id(x, y, n) (x * n + y)

struct UnionSet {
    int cnt;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : cnt(0), fa(n) {
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

vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    int ind = 0;
    unordered_map<int, int> mp;
    unordered_set<int> st;
    vector<int> ans;
    for (auto &x : positions) {
        if (mp.count(id(x[0], x[1], n))) continue;
        mp[id(x[0], x[1], n)] = ind++;
    }
    UnionSet u(ind);
    for (auto &x : positions) {
        if (st.count(id(x[0], x[1], n))) {
            ans.push_back(u.cnt);
            continue;
        }
        st.insert(id(x[0], x[1], n));
        u.cnt++;
        for (int i = 0; i < 4; i++) {
            int x_t = x[0] + dir[i][0];
            int y_t = x[1] + dir[i][1];
            if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || !st.count(id(x_t, y_t, n))) continue;
            u.merge(mp[id(x[0], x[1], n)], mp[id(x_t, y_t, n)]);
        }
        ans.push_back(u.cnt);
    }
    return ans;
}

int main() {
    return 0;
}
