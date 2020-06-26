/*************************************************************************
	> File Name: 3.LeetCode877.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月26日 星期五 15时56分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

bool stoneGame(vector<int> &piles) {
    int dp[piles.size() + 5][piles.size() + 5][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < piles.size(); i++) {
        dp[i][i][0] = piles[i];
    }
    for (int l = 1; l < piles.size(); l++) {
        for (int i = 0; i + l < piles.size(); i++) {
            int j = i + l;
            dp[i][j][0] = max(piles[i] + dp[i + 1][j][1], piles[i + l] + dp[i][j - 1][1]);
            if (piles[i] + dp[i + 1][j][1] >= piles[j] + dp[i][j - 1][1]) dp[i][j][1] = dp[i + 1][j][0];
            else dp[i][j][1] = dp[i][j - 1][0]; 
        }
    }
    cout << dp[0][piles.size() - 1][0] << " " << dp[0][piles.size() - 1][1] << endl;
    return dp[0][piles.size() - 1][0] > dp[0][piles.size() - 1][1];
}
 
int main() {
    int n, x;
    vector<int> piles;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        piles.push_back(x);
    }
    cout << (stoneGame(piles) ? "true" : "false") << endl;
    return 0;
}
