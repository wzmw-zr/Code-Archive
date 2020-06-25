/*************************************************************************
	> File Name: 2.LeetCode139.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月25日 星期四 20时46分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

bool check(int start, int end, string s, vector<string> &wordDict) {
    string tmp = "";
    for (int i = start - 1; i <= end - 1; i++) tmp += s[i];
    for (int i = 0; i < wordDict.size(); i++) {
        if (tmp == wordDict[i]) return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int dp[s.size() + 5];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (!dp[j] || !check(j + 1, i, s, wordDict)) continue;
            dp[i] = 1;
            break;
        }
    }
    return dp[s.size()];
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<string> wordDict;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        wordDict.push_back(tmp);
    }
    if (wordBreak(s, wordDict)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
