/*************************************************************************
	> File Name: 7.LeetCode1402.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月30日 星期二 18时58分13秒
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

int maxSatisfaction(vector<int>& satisfaction) {
    int s_len = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

#if 0
    for (int i = 0; i < s_len; i++) cout << satisfaction[i] << " ";
    cout << endl;
#endif

    int dp[s_len + 5][s_len + 5];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s_len; i++) {
        dp[i][i] = dp[i - 1][i - 1] + i * satisfaction[i - 1];
    }
    int res = 0;
    for (int i = 1; i <= s_len; i++) {
        for (int j = i + 1; j <= s_len; j++) {
#if 0
            cout << "i = " << i << " j = " << j << " " << dp[i][j - 1] << " " << dp[i - 1][j - 1] << endl;
            res = max(res, dp[i][j]);
            cout << dp[i][j] << endl;
#endif
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + i * satisfaction[j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= s_len; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> satisfaction;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        satisfaction.push_back(x);
    }
    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}
