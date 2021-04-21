/*************************************************************************
	> File Name: 1.LeetCode363.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月22日 星期四 00时04分19秒
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

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int pre_sum[m + 1][n + 1];
    memset(pre_sum, 0, sizeof(pre_sum));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) pre_sum[i + 1][j + 1] = pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j] + matrix[i][j];
    }
    int ans = INT32_MIN;
    for (int x = 1; x <= m && ans < k; x++) {
        for (int y = 1; y <= n && ans < k; y++) {
            for (int i = 0; i + x <= m && ans < k; i++) {
                for (int j = 0; j + y <= n && ans < k; j++) {
                    int sum = pre_sum[i + x][j + y] - pre_sum[i + x][j] - pre_sum[i][j + y] + pre_sum[i][j];
                    if (sum > k) continue;
                    ans = max(ans, sum);
                }
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
