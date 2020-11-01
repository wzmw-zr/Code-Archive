/*************************************************************************
	> File Name: 2.LeetCode140.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月01日 星期日 08时10分28秒
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

vector<string> dfs(string s, vector<string> &wordDict, unordered_map<string, vector<string>> &mp) {
    if (s.size() == 0) return vector<string>(1, "");
    if (mp.count(s)) return mp[s];
    vector<string> ans;
    for (auto &x : wordDict) {
        if (s.size() < x.size()) continue;
        if (s.substr(0, x.size()) == x) {
            auto ret = dfs(s.substr(x.size()), wordDict, mp);
            for (auto &y : ret) {
                if (y.size()) ans.push_back(x + " " + y);
                else ans.push_back(x);
            }
        }
    }
    mp[s] = ans;
    return ans;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> mp;
    dfs(s, wordDict, mp);
    return mp[s];
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
