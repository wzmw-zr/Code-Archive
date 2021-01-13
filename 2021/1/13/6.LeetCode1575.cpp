/*************************************************************************
	> File Name: 6.LeetCode1575.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月13日 星期三 22时57分17秒
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
            if (j == finish) continue;
            for (int k = 0; k < n; k++) {
                if (i < abs(locations[j] - locations[k])) continue;
                if (j == k) continue;
                dp[j][i] += dp[k][i - abs(locations[j] - locations[k])];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << "th : ";
        for (int j = 0; j <= fuel; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[start][fuel];
}


#if 0
int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    if (fuel < 0) return 0;
    int ans = 0, n = locations.size();
    if (start == finish) ans += 1;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        ans += countRoutes(locations, i, finish, fuel - abs(locations[start] - locations[i]));
        ans %= 1000000007;
    }
    return ans;
}
#endif 


int main() {
    return 0;
}
