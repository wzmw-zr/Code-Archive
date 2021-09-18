/*************************************************************************
	> File Name: 2.LeetCode292.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月18日 星期六 09时00分01秒
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
using namespace std;

bool canWinNim(int n) {
    vector<int> dp(n + 5, 0);
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++) dp[i] = !(dp[i - 1] & dp[i - 2] & dp[i - 3]);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << endl;
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << (canWinNim(n) ? "True" : "False") << endl;
    return 0;
}
