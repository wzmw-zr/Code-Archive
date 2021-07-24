/*************************************************************************
	> File Name: 1.LeetCode1743.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月25日 星期日 00时03分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    int n = adjacentPairs.size() + 1;
    unordered_map<int, vector<int>> mp;
    for (auto p : adjacentPairs) {
        if (!mp.count(p[0])) mp[p[0]] = vector<int>{};
        if (!mp.count(p[1])) mp[p[1]] = vector<int>{};
        mp[p[0]].push_back(p[1]);
        mp[p[1]].push_back(p[0]);
    }
    vector<int> ans;
    unordered_set<int> st;
    int pre;
    for (auto &&[num, adj] : mp) {
        if (adj.size() == 2) continue;
        pre = num;
        break;
    }
    ans.push_back(pre);
    st.insert(pre);
    while (ans.size() != n) {        
        for (int x : mp[pre]) {
            if (st.count(x)) continue;
            ans.push_back(x);
            st.insert(x);
            pre = x;
        }
    }
    return ans;
}

int main() {
    return 0;
}
