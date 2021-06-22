/*************************************************************************
	> File Name: 1.LeetCode1985.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月22日 星期二 08时14分01秒
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

void dfs(string res, string &s, vector<int> &check, unordered_set<string> &all_strs) {
    if (res.size() == s.size()) {
        all_strs.insert(res);
        return ;
    }
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        dfs(res + s[i], s, check, all_strs);
        check[i] = 0;
    }
}

vector<string> permutation(string s) {
    int n = s.size();
    vector<int> check(n, 0);
    unordered_set<string> all_strs;
    dfs("", s, check, all_strs);
    vector<string> ans;
    for (auto s : all_strs) ans.push_back(s);
    return ans;
}

int main() {
    return 0;
}
