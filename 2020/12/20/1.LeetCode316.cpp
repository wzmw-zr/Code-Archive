/*************************************************************************
	> File Name: 1.LeetCode316.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月20日 星期日 07时53分13秒
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

void dfs(string &s, unordered_set<char> &st, unordered_set<char> &check, vector<string> &ans, int ind, string path, int cnt) {
    if (cnt == st.size()) {
        ans.push_back(path);
        return ;
    }
    for (int i = ind; i < s.size(); i++) {
        if (check.count(s[i])) continue;
        check.insert(s[i]);
        dfs(s, st, check, ans, i + 1, path + s[i], cnt + 1);
        check.erase(check.find(s[i]));
    }
}

string removeDuplicateLetters(string s) {
    unordered_set<char> st;
    unordered_set<char> check;
    for (char c : s) st.insert(c);
    int n = st.size();
    vector<string> ans;
    for (int i = 0; i < s.size(); i++) dfs(s, st, check, ans, i, "", 0);
    sort(ans.begin(), ans.end());
    return ans[0];
}

int main() {
    string s;
    cin >> s;
    cout << removeDuplicateLetters(s) << endl;
    return 0;
}
