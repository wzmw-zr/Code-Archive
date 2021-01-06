/*************************************************************************
	> File Name: 5.LeetCode721.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 01时30分10秒
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

void dfs(vector<vector<string>> &accounts, unordered_map<string, vector<int>> &mp, unordered_map<string, bool> &check, vector<bool> &handled, vector<string> &temp, int ind) {
    if (handled[ind]) return ;
    for (int i = 1; i < accounts[ind].size(); i++) {
        if (check[accounts[ind][i]]) continue;
        temp.push_back(accounts[ind][i]);
        check[accounts[ind][i]] = true;
    }
    handled[ind] = true;
    for (int i = 1; i < accounts[ind].size(); i++) {
        for (int x : mp[accounts[ind][i]]) dfs(accounts, mp, check, handled, temp, x);
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<int>> mp;
    unordered_map<string, bool> check;
    vector<bool> handled((int) accounts.size(), false);
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (!mp.count(accounts[i][j])) mp[accounts[i][j]] = vector<int>(0);
            mp[accounts[i][j]].push_back(i);
            check[accounts[i][j]] = false;
        }
    }
    vector<vector<string>> ans;
    for (int i = 0; i < accounts.size(); i++) {
        if (handled[i]) continue;
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        dfs(accounts, mp, check, handled, temp, i);
        sort(temp.begin() + 1, temp.end());
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
