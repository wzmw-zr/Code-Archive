/*************************************************************************
	> File Name: 3.LeetCode1510.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月15日 星期二 09时00分01秒
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

bool winnerSquareGame(int n) {
    bool dp[n + 5];
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; i--) {
        int len = n - i + 1;
        for (int j = 1; j * j <= len; j++) {
            if (dp[i + j * j]) continue;
            dp[i] = true;
            break;
        }
    }
    return dp[1];
}

int main() {
    int n;
    cin >> n;
    cout << (winnerSquareGame(n) ? "Yes" : "No") << endl;
    return 0;
}
