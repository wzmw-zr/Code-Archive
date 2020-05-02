/*************************************************************************
	> File Name: 3.LeetCode5.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月02日 星期六 13时47分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

string longestPalindrome(string s) {
    string ret;
    if (s.size() == 0) return ret;
    int dp[s.size() + 5][s.size() + 5];
    memset(dp, 0, sizeof(dp));
    int l = 0, r = 0, len = 1;
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            l = i, r = i + 1, len = 2;
            dp[i][i + 1] = 2;
        }
    }
    for (int i = 2; i < s.size(); i++) {
        for (int j = 0; j < s.size() - i; j++) {
            if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) {
                dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
                if (dp[j][j + i] > len) l = j, r = j + i; 
            }
            else dp[j][j + i] = 0;
        }
    }
    for (int i = l; i <= r; i++) ret += s[i];
    return ret;
}

int main() {
    string s;
    cin >> s;
    s = "";
    cout << longestPalindrome(s) << endl;
    return 0;
}
