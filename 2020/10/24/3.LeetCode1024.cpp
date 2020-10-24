/*************************************************************************
	> File Name: 3.LeetCode1024.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月24日 星期六 08时43分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int videoStitching(vector<vector<int>>& clips, int T) {
    vector<int> dp(T + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= T; i++) {
        for (auto &x : clips) {
            if (x[0] < i && x[1] >= i) dp[i] = min(dp[i], dp[x[0]] + 1);
        }
    }
    return dp[T] == 0x3f3f3f3f ? -1 : dp[T];
}

int main() {
    return 0;
}
