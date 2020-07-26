/*************************************************************************
	> File Name: 1.LeetCode329.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月26日 星期日 00时47分27秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<int>> &check, int x, int y, int path_len, int &ans, int pre) {
    int len = matrix.size();
    int width = matrix[0].size();
    if (x < 0 || y < 0 || x >= len || y >= width) {
        ans = max(ans, len);
        return ;
    }
    if (matrix[x][y] <= pre) {
        ans = max(ans, len);
        return ;
    }
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || y_t < 0 || x_t >= len || y_t >= width) {
            ans = max(ans, len);
            continue;
        }
        if (check[x_t][y_t]) {
            ans = max(ans, len);
            continue;
        }
        check[x_t][y_t] = 1;
        longestIncreasingPath(matrix, check, x_t, y_t, path_len + 1, ans, matrix[x][y]);
        check[x_t][y_t] = 0;
    }
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int len = matrix.size();
    if (len == 0) return 0;
    int width = matrix[0].size();
    int ans = 0;
    vector<vector<int>> check(len + 5, vector<int>(width + 5, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++) {
            check[i][j] = 1;
            longestIncreasingPath(matrix, check, i ,j, 1, ans, INT32_MIN);
            check[i][j] = 0;
        }
    }
    return ans;
}

int main() {
    return 0;
}
