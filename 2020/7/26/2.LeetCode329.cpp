/*************************************************************************
	> File Name: 2.LeetCode329.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月26日 星期日 07时13分47秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<unistd.h>
using namespace std;


int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<int>> &check, int x, int y) {
    if (check[x][y]) return check[x][y];
    check[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t >= 0 && y_t >= 0 && x_t < matrix.size() && y_t < matrix[0].size() && matrix[x_t][y_t] > matrix[x][y]) {
            check[x][y] = max(check[x][y], longestIncreasingPath(matrix, check, x_t, y_t) + 1);
        }
    }
    return check[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int len = matrix.size();
    int width = matrix[0].size();
    int ans = 0;
    vector<vector<int>> check(len + 5, vector<int>(width + 5, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++) {
            ans = max(ans, longestIncreasingPath(matrix, check, i, j));
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}
