/*************************************************************************
	> File Name: 1.LeetCode1620.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月01日 星期四 07时20分07秒
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
#include<algorithm>
using namespace std;

#define isRed(c) (c == 'r' ? 1 : 0)
#define isYellow(c) (c == 'y' ? 1 : 0)

int minimumOperations(string leaves) {
    int len = leaves.size();
    int dp[len + 5][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = isYellow(leaves[0]);
    dp[1][1] = dp[0][0] + isRed(leaves[1]);
    dp[2][2] = dp[1][1] + isYellow(leaves[2]);
    for (int i = 1; i < len; i++) dp[i][0] = dp[i - 1][0] + isYellow(leaves[i]);
    for (int i = 2; i < len; i++) dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + isRed(leaves[i]);
    for (int i = 3; i < len; i++) dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + isYellow(leaves[i]);
    return dp[len - 1][2];
}

int main() {
    string leaves;
    cin >> leaves;
    cout << minimumOperations(leaves) << endl;
    return 0;
}
