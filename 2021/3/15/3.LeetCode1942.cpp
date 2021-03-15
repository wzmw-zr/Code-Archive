/*************************************************************************
	> File Name: 3.LeetCode1942.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 10时43分13秒
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

void dfs(unordered_map<char, int> &mp, unordered_set<string> &st, string &s, int ind, int &n) {
    if (ind == n) {
        st.insert(s);
        return ;
    }
    for (auto &&[c, cnt] : mp) {
        if (cnt == 0) continue;
        mp[c]--;
        s[ind] = c;
        dfs(mp, st, s ,ind + 1, n);
        mp[c]++;
    }
}

vector<string> permutation(string S) {
    int n = S.size();
    unordered_map<char, int> mp;
    unordered_set<string> st;
    vector<string> ans;
    for (int i = 0; S[i]; i++) mp[S[i]]++;
    string s(n, ' ');
    dfs(mp, st, s, 0, n);
    for (auto x : st) ans.push_back(x);
    return ans;
}

int main() {
    string S;
    cin >> S;
    auto ans = permutation(S);
    for (auto s : ans) cout << s << endl;
    return 0;
}
