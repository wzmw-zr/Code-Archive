/*************************************************************************
	> File Name: 2.LeetCode1074.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月29日 星期六 00时29分14秒
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

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int pre[n + 1][m + 1];
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            pre[i + 1][j + 1] = matrix[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
    int ans = 0;
    for (int h = 1; h <= n; h++) {
        for (int i = 0; (i + h - 1) < n; i++) {
            unordered_map<int, int> mp;
            int pre_sum = 0;
            mp[0] = 1;
            for (int j = 0; j < m; j++) {
                int x1 = i, y1 = j, x2 = i + h - 1, y2 = j;
                int t = pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1];
                pre_sum += t;
                if (mp.count(pre_sum - target)) ans += mp[pre_sum - target];
                mp[pre_sum]++;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
