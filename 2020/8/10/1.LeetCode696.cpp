/*************************************************************************
	> File Name: 1.LeetCode696.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月10日 星期一 00时26分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int check(char x, char y) {
    if ((x == '0') && (y == '1')) return 1;
    if ((x == '1') && (y == '0')) return 1;
    return 0;
}

int countBinarySubstrings(string s) {
    vector<vector<int>> dp(s.size() + 5, vector<int>(s.size() + 5, 0));
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (check(s[i], s[i + 1])) {
            dp[i][i + 1] = 1;
            ans++;
        }
    }
    for (int len = 4; len <= s.size(); len += 2) {
        for (int i = 0; i < s.size() - len + 1; i++) {
            if ((s[i] == s[i + 1]) && (s[i + len - 1] == s[i + len - 2])) {
                dp[i][i + len - 1] = dp[i + 1][i + len - 2];
                ans += dp[i + 1][i + len - 2];
                if (dp[i + 1][i + len - 2]) {
                    cout << s.substr(i, len) << endl;
                }
            }
        }
    }
    return ans;
}

int new_countBinarySubstrings(string s) {
    vector<int> dp(s.size() + 5, 0);
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (check(s[i], s[i + 1])) {
            dp[i] = 1;
            ans++;
        }
    }
    for (int len = 4; len <= s.size(); len += 2) {
        for (int i = 0; i < s.size() - len + 1; i++) {
            if ((s[i] == s[i + 1]) && (s[i + len - 1] == s[i + len - 2])) {
                dp[i] = dp[i + 1];
                ans += dp[i + 1];
            }
        }
    }
    return ans;
}

int CountBinarySubstrings(string s) {
    vector<int> num;
    char pre = s[0];
    int cnt = 1, ind = 1;
    while (ind < s.size()) {
        if (s[ind] == pre) cnt++;
        else {
            num.push_back(cnt);
            pre = s[ind];
            cnt = 1;
        }
        ind++;
    }
    num.push_back(cnt);
    int ans = 0;
    for (int i = 0; i < num.size() - 1; i++) ans += min(num[i], num[i + 1]);
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << CountBinarySubstrings(s) << endl;
    return 0;
}
