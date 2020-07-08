/*************************************************************************
	> File Name: 2.LeetCode1690.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月09日 星期四 01时07分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int respace(vector<string>& dictionary, string sentence) {
    int s_len = sentence.size();
    unordered_map<string, int> mp;
    vector<int> dp(s_len + 5, 0);
    for (auto x : dictionary) mp[x] = 1;
    for (int i = 1; i <= s_len; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            if (!mp[sentence.substr(j, i - j)]) continue;
            dp[i] = min(dp[i], dp[j]);
        }
    }
    return dp[s_len];
}

int main() {
    return 0;
}
