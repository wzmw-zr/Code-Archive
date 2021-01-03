/*************************************************************************
	> File Name: 4.LeetCode1864.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月03日 星期日 09时45分03秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

int countEval(string s, int result) {
    int n = s.size();
    int cnt = (n + 1) / 2;
    int nums[cnt];
    int dp[cnt][cnt][2];
    memset(nums, 0, sizeof(nums));
    memset(dp, 0, sizeof(dp));
    for (int i = 0, j = 0; i < n; i += 2, j++) nums[j] = s[i] - '0';
    for (int i = 0; i < cnt; i++) {
        dp[i][i][0] = (nums[i] == 0 ? 1 : 0);
        dp[i][i][1] = (nums[i] == 1 ? 1 : 0);
    }
    for (int len = 2; len <= cnt; len++) {
        for (int i = 0; i + len - 1 < cnt; i++) {
            for (int j = 1; j < len; j++) {
                char c = s[2 * (i + j - 1) + 1];
                if (c == '|') {
                    dp[i][i + len - 1][0] += dp[i][i + j - 1][0] * dp[i + j][i + len - 1][0];
                    dp[i][i + len - 1][1] += dp[i][i + j - 1][0] * dp[i + j][i + len - 1][1] + dp[i][i + j - 1][1] * dp[i + j][i + len - 1][1] + dp[i][i + j - 1][1] * dp[i + j][i + len - 1][0];
                } else if (c == '&') {
                    dp[i][i + len - 1][0] += dp[i][i + j - 1][0] * dp[i + j][i + len - 1][0] + dp[i][i + j - 1][0] * dp[i + j][i + len - 1][1] + dp[i][i + j - 1][1] * dp[i + j][i + len - 1][0];
                    dp[i][i + len - 1][1] += dp[i][i + j - 1][1] * dp[i + j][i + len - 1][1];
                } else {
                    dp[i][i + len - 1][0] += dp[i][i + j - 1][0] * dp[i + j][i + len - 1][0] + dp[i][i + j - 1][1] * dp[i + j][i + len - 1][1];
                    dp[i][i + len - 1][1] += dp[i][i + j - 1][0] * dp[i + j][i + len - 1][1] + dp[i][i + j - 1][1] * dp[i + j][i + len - 1][0];
                }
            }
        }
    }
    return dp[0][cnt - 1][result];
}

int main() {
    string s;
    int result;
    cin >> s >> result;
    cout << countEval(s, result) << endl;
    return 0;
}
