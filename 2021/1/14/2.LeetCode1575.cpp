/*************************************************************************
	> File Name: 2.LeetCode1575.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月14日 星期四 00时13分16秒
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

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int n = locations.size();
    int dp[n][fuel + 1];
    memset(dp, 0, sizeof(dp));
    dp[finish][0] = 1;
    for (int i = 1; i <= fuel; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                int dis = abs(locations[j] - locations[k]);
                if (dis > i) continue;
                dp[j][i] += dp[k][i - dis];
                dp[j][i] %= 1000000007;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= fuel; i++) ans = (ans + dp[start][i]) % 1000000007;
    for (int i = 0; i < n; i++) {
        cout << i << "th: ";
        for (int j = 0; j <= fuel; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    return ans;
}

int main() {
    return 0;
}
