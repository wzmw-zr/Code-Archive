/*************************************************************************
	> File Name: 3.LeetCode305.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月18日 星期一 20时40分56秒
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

string ch_to_string(int x, int y) {
    return to_string(x) + ", " + to_string(y);
}

vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    int ind = 0;
    unordered_map<string, int> mp;
    unordered_map<string, int> check;
    vector<int> ans;
    for (auto &x : positions) mp[ch_to_string(x[0], x[1])] = ind++;
    UnionSet u(ind);
    for (auto &x : positions) {
        string s = ch_to_string(x[0], x[1]);
        if (check[s]) {
            ans.push_back(u.cnt);
            continue;
        }
        check[s] = 1;
        u.cnt++;
        for (int i = 0; i < 4; i++) {
            int x_t = x[0] + dir[i][0];
            int y_t = x[1] + dir[i][1];
            string temp = ch_to_string(x_t, y_t);
            if (!mp.count(temp)) continue;
            if (!check[temp]) continue;
            u.merge(mp[s], mp[temp]);
        }
        ans.push_back(u.cnt);
    }
    return ans;
}

int main() {
    return 0;
}
