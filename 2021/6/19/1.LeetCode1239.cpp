/*************************************************************************
	> File Name: 1.LeetCode1239.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月19日 星期六 00时09分38秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void dfs(vector<string> &strs, int ind, int &n, vector<int> &check, int len, int &ans) {
    if (ind == n) {
        ans = max(ans, len);
        return ;
    }
    dfs(strs, ind + 1, n, check, len, ans);
    int flag = 0;
    for (char c : strs[ind]) {
        if (check[c - 'a']) {
            flag = 1;
            break;
        }
    }
    if (flag) return ;
    for (char c : strs[ind]) check[c - 'a'] = 1;
    dfs(strs, ind + 1, n, check, len + strs[ind].size(), ans);
    ans = max(ans, len + (int) strs[ind].size());
    for (char c : strs[ind]) check[c - 'a'] = 0;
}

int maxLength(vector<string>& arr) {
    vector<string> strs;
    for (string &s : arr) {
        vector<int> check(26, 0);
        int flag = 0;
        for (char c : s) {
            if (check[c - 'a']) {
                flag = 1;
                break;
            }
            check[c - 'a'] = 1;
        }
        if (flag) continue;
        strs.push_back(s);
    }
    vector<int> check(26, 0);
    int n = strs.size();
    int ans = 0;
    dfs(strs, 0, n, check, 0, ans);
    return ans;
}

int main() {
    return 0;
}
