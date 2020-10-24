/*************************************************************************
	> File Name: 1.LeetCode1024.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月24日 星期六 07时38分55秒
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

int videoStitching(vector<vector<int>>& clips, int T) {
    clips.push_back({0, 0});
    sort(clips.begin(), clips.end(), [](vector<int> &a, vector<int> &b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
    int len = clips.size();
    if (clips[len - 1][1] < T) return -1;
    int dp[len + 5];
    int ans = 0x3f3f3f3f;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < len; i++) {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (clips[j][1] >= clips[i][0]) {
                flag = 1;
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        if (!flag) return -1;
        if (clips[i][1] >= T) ans = min(ans, dp[i]);
    }
    return ans;
}

int main() {
    return 0;
}
