/*************************************************************************
	> File Name: 2.LeetCode375.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月12日 星期五 08时25分13秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int getMoneyAmount(int n) {
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int t = INT32_MAX;
            for (int j = i; j <= i + l - 1; j++) {
                int x = (j - 1 >= i) ? dp[i][j - 1] : 0;
                int y = (j + 1 <= i + l - 1) ? dp[j + 1][i + l - 1] : 0;
                t = min(t, max(x, y) + j);
            }
            dp[i][i + l - 1] = t;
        }
    }
    return dp[1][n];
}

int main() {
    int n;
    cin >> n;
    cout << getMoneyAmount(n) << endl;
    return 0;
}
