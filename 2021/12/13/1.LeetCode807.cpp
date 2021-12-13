/*************************************************************************
	> File Name: 1.LeetCode807.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月13日 星期一 08时12分57秒
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

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) rows[i] = max(rows[i], grid[i][j]), cols[j] = max(cols[j], grid[i][j]);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) ans += min(rows[i], cols[j]) - grid[i][j];
    }
    return ans;
}

int main() {
    return 0;
}
