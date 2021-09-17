/*************************************************************************
	> File Name: 2.LeetCode2002.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月17日 星期五 17时09分45秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int maxProduct(string s) {
    int n = s.size();
    int dp[1 << n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < 1 << n; i++) {
        int cnt = __builtin_popcount(i);
        if (cnt == 1) {
            dp[i] = 1;
        } else {
            int l = __builtin_ctz(i);
            int r = 31 - __builtin_clz(i);
            dp[i] = s[l] == s[r] ? dp[i - (1 << l) - (1 << r)] : 0;
        }
    }
    int ans = 0;
    for (int i = 1; i < 1 << n; i++) {
        if (!dp[i]) continue;
        int x = (1 << n) - 1 - i;
        for (int j = x; j; j = x & (j - 1)) {
            if (dp[j]) ans = max(ans, __builtin_popcount(i) * __builtin_popcount(j));
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << maxProduct(s) << endl;
    return 0;
}
