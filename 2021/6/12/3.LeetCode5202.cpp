/*************************************************************************
	> File Name: 3.LeetCode5202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月12日 星期六 22时38分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(int x, int y, int k, vector<vector<int>> &grid, vector<vector<int>> &rows, vector<vector<int>> &cols) {
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    t1 = rows[x + 1][y + k] - rows[x + 1][y];
    for (int i = 2; i <= k; i++) {
        if ((rows[x + i][y + k] - rows[x + i][y]) == t1) continue;
        return false;
    }
    t2 = cols[x + k][y + 1] - cols[x][y + 1];
    if (t1 != t2) return false;
    for (int i = 2; i <= k; i++) {
        if ((cols[x + k][y + 1] - cols[x][y + 1]) == t1) continue;
        return false;
    }
    for (int i = 0; i < k; i++) t3 += grid[x + i][y + i];
    if (t1 != t3) return false;
    for (int i = 0, j = k - 1; i < k; i++, j--) t4 += grid[x + i][y + j];
    if (t1 != t4) return false;
    return true;
}

int largestMagicSquare(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> rows(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> cols(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rows[i][j] = rows[i][j - 1] + grid[i - 1][j - 1];
            cols[i][j] = cols[i - 1][j] + grid[i - 1][j - 1];
        }
    }
    int mmin = min(n, m);
    int ans = 1;
    for (int k = 2; k <= mmin; k++) {
        int flag = 0;
        for (int i = 0; i + k - 1 < n; i++) {
            for (int j = 0; j + k - 1 < m; j++) {
                if (!check(i, j, k, grid, rows, cols)) continue;
                flag = 1;
                ans = k;
                break;
            }
            if (flag) break;
        }
    }
    return ans;
}

int main() {
    return 0;
}
