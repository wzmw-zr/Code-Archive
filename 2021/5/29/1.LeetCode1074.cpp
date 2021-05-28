/*************************************************************************
	> File Name: 1.LeetCode1074.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月29日 星期六 00时05分25秒
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            pre[i + 1][j + 1] = matrix[i][j] + pre[i + 1][j] + pre[i][j + 1]  - pre[i][j];
    }
    int ans = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < m; y2++) {
                    int t = pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1];
                    if (t == target) ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
