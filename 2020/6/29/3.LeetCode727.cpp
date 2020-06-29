/*************************************************************************
	> File Name: 3.LeetCode727.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月29日 星期一 15时13分42秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

string minWindow(string S, string T) {
    int s_len = S.size(), t_len = T.size();
    vector<vector<int>> dp(t_len + 5, vector<int>(s_len + 5, -1));
    dp[0][0] = (S[0] == T[0] ? 0 : -1);
    for (int i = 1; i < s_len; i++) {
        dp[0][i] = (T[0] == S[i] ? i : dp[0][i - 1]);
    }
    for (int i = 1; i < t_len; i++) {
        for (int j = i; j < s_len; j++) {
            dp[i][j] = (T[i] == S[j] ? dp[i - 1][j - 1] : dp[i][j - 1]);
        }
    }
    int left = 0, right = s_len - 1;
    for (int i = 0; i < s_len; i++) {
        if (dp[t_len - 1][i] == -1) continue;
        if (i - dp[t_len - 1][i] + 1 >= right - left + 1) continue;
        left = dp[t_len - 1][i];
        right = i;
    }
    if (right >= s_len - 1) return "";
    return S.substr(left, right - left + 1);
}

int main() {
    return 0;
}
