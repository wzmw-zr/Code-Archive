/*************************************************************************
	> File Name: 4.LeetCode1260.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月20日 星期二 22时10分02秒
 ************************************************************************/

#include<iostream>
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

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    k %= m * n;
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int col = (j + k) % n;
            int row = (i + (j + k) / n) % m;
            ans[row][col] = grid[i][j];
        }
    }
    return ans;
}

int main() {
    return 0;
}
