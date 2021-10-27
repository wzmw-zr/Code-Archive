/*************************************************************************
	> File Name: 1.LeetCode301.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月27日 星期三 12时18分25秒
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

bool is_valid(string &s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') cnt++; 
        else if (c == ')') {
            if (cnt == 0) return false;
            cnt--;
        }
    }
    return true;
}

void dfs(string &s, int ind, vector<int> &check, int r_lbrace, int r_rbrace, int lbrace, unordered_set<string> &ans) {
    if (!r_lbrace && !r_rbrace) {
        string t = "";
        int n = check.size();
        for (int i = 0; i < n; i++) {
            if (check[i]) continue;
            t += s[i];
        }
        if (is_valid(t)) ans.insert(t);
        return ;
    }
    if (!s[ind]) return ;
    if (s[ind] == '(') {
        dfs(s, ind + 1, check, r_lbrace, r_rbrace, lbrace + 1, ans);
        if (!r_lbrace) return ;
        check[ind] = 1;
        dfs(s, ind + 1, check, r_lbrace - 1, r_rbrace, lbrace, ans);
        check[ind] = 0;
    } else if (s[ind] == ')') {
        if (lbrace) dfs(s, ind + 1, check, r_lbrace, r_rbrace, lbrace - 1, ans);
        if (!r_rbrace) return ;
        check[ind] = 1;
        dfs(s, ind + 1, check, r_lbrace, r_rbrace - 1, lbrace, ans);
        check[ind] = 0;
    } else {
        dfs(s, ind + 1, check, r_lbrace, r_rbrace, lbrace, ans);
    }
}

vector<string> removeInvalidParentheses(string s) {
    int n = s.size();
    int lbrace = 0;
    int rbrace = 0;
    for (char c : s) {
        if (c == '(') lbrace++; 
        else if (c == ')') {
            if (lbrace == 0) rbrace++;
            else lbrace--;
        }
    }

    vector<int> check(n, 0);
    unordered_set<string> ans;
    int ind = 0;
    dfs(s, ind, check, lbrace, rbrace, 0, ans);
    vector<string> res;
    for (auto &&s : ans) res.push_back(move(s));
    return res;
}

int main() {
    string s;
    cin >> s;
    auto ans = removeInvalidParentheses(s);
    for (auto x : ans) cout << x << endl;
    return 0;
}
