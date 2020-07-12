/*************************************************************************
	> File Name: 3.LeetCode174.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月12日 星期日 10时35分18秒
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

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int x_len = dungeon.size(), y_len = dungeon[0].size();
    vector<vector<int>> dp(x_len + 5, vector<int>(y_len + 5, 0x3f3f3f3f));
    dp[x_len][y_len - 1]= dp[x_len - 1][y_len] = 1;
    for (int i = x_len - 1; i >= 0; i--) {
        for (int j = y_len - 1; j >= 0; j--) {
            int mmin = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(mmin - dungeon[i][j], 1);
        }
    }
    return dp[0][0];
}

int main() {
    return 0;
}
