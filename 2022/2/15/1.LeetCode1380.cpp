/*************************************************************************
	> File Name: 1.LeetCode1380.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月15日 星期二 09时55分30秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> rows(m, INT32_MAX), cols(n, INT32_MIN);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rows[i] = min(rows[i], matrix[i][j]);
            cols[j] = max(cols[j], matrix[i][j]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == rows[i] && matrix[i][j] == cols[j]) {
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
