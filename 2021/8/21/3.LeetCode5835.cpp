/*************************************************************************
	> File Name: 3.LeetCode5835.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月21日 星期六 22时37分39秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long ans = 0;
    vector<long long> pos_nums;
    vector<long long> neg_nums;
    for (auto &x : matrix) {
        for (auto &y : x) {
            if (y >= 0) pos_nums.push_back(y);
            if (y < 0) neg_nums.push_back(y);
        }
    }
    sort(pos_nums.begin(), pos_nums.end());
    sort(neg_nums.begin(), neg_nums.end());
    int n = neg_nums.size();
    int m = pos_nums.size();
    if (n & 1) {
        for (long long x : pos_nums) ans += x;
        for (int i = 0; i + 1 < n; i += 2) ans += abs(neg_nums[i]) + abs(neg_nums[i + 1]);
        if (m == 0 || abs(neg_nums[n - 1]) <= pos_nums[0]) ans += neg_nums[n - 1];
        else ans += abs(neg_nums[n - 1]) - 2L * pos_nums[0];
    } else {
        for (long long x : pos_nums) ans += x;
        for (long long x : neg_nums) ans += -1L * x;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }
    cout << maxMatrixSum(matrix) << endl;
    return 0;
}
