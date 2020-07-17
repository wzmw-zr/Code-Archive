/*************************************************************************
	> File Name: 2.LeetCode97.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月18日 星期六 00时38分29秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<vector<int>> dp(s1.size() + 5, vector<int>(s2.size() + 5, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 && j == 0) continue;
            //cout << s1[i - 1] << " " << s2[j - 1] << " " << s3[i + j - 1] << endl;
            if (i && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                dp[i][j] = 1;
            } 
            if (j && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                dp[i][j] = 1;
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << (isInterleave(s1, s2, s3) ? "True" : "False") << endl;
    return 0;
}
