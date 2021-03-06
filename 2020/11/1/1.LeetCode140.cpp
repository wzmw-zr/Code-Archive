/*************************************************************************
	> File Name: 1.LeetCode140.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月01日 星期日 07时45分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

void dfs(string &s, vector<string> &wordDict, vector<string> &ans, string str, int ind, int flag) {
    int n = s.size();
    int len = n - ind;
    if (len == 0) {
        ans.push_back(str);
        return ;
    }
    for (auto &x : wordDict) {
        if (len < x.size()) continue;
        if (s.substr(ind, x.size()) == x) {
            if (!flag) {
                dfs(s, wordDict, ans, str + x, ind + x.size(), 1);
            } else {
                dfs(s, wordDict, ans, str + " " + x, ind + x.size(), flag);
            }
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans;
    dfs(s, wordDict, ans, "", 0, 0);
    return ans;
}

int main() {
    string s, s_t;
    cin >> s;
    vector<string> wordDict;
    while (cin >> s_t) wordDict.push_back(s_t);
    auto ans = wordBreak(s, wordDict);
    for (auto &x : ans) cout << x << endl;
    return 0;
}
