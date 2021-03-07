/*************************************************************************
	> File Name: 1.LeetCode131.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月07日 星期日 08时03分48秒
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

void dfs(string &s, vector<vector<string>> &ans, vector<string> &path, vector<vector<int>> &palindrome,  int ind, int n) {
    if (ind == n) {
        ans.push_back(path);
        return ;
    }
    for (int &x : palindrome[ind]) {
        path.push_back(s.substr(ind, x - ind + 1));
        dfs(s, ans, path, palindrome, x + 1, n);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> palindrome(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        palindrome[i].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) continue;
        dp[i][i + 1] = 1;
        palindrome[i].push_back(i + 1);
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            if (s[i] == s[i + l - 1]) {
                dp[i][i + l - 1] = dp[i + 1][i + l - 2]; 
                if (dp[i][i + l - 1]) palindrome[i].push_back(i + l - 1);
            }
        }
    }
    vector<vector<string>> ans;
    vector<string> path;
    dfs(s, ans, path, palindrome, 0, n);
    return ans;
}

int main() {
    return 0;
}
