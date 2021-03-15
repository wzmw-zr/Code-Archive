/*************************************************************************
	> File Name: 2.LeetCode1941.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 10时31分32秒
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

void dfs(unordered_map<char, int> &characters, vector<string> &ans, string &s, int ind, int &n) {
    if (ind == n) {
        ans.push_back(s);
        return ;
    }
    for (auto &&[c, cnt] : characters) {
        if (cnt == 0) continue;
        characters[c] = 0;
        s[ind] = c;
        dfs(characters, ans, s, ind + 1, n);
        characters[c] = 1;
    }
}

vector<string> permutation(string S) {
    int n = S.size();
    unordered_map<char, int> characters;
    for (int i = 0; S[i]; i++) characters[S[i]] = 1;
    string s(n, ' ');
    vector<string> ans;
    dfs(characters, ans, s, 0, n);
    return ans;
}

int main() {
    string S;
    cin >> S;
    auto ans = permutation(S);
    for (auto s : ans) cout << s << endl;
    return 0;
}
