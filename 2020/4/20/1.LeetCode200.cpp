/*************************************************************************
	> File Name: 1.LeetCode200.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月20日 星期一 08时51分05秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void FindLand(vector<vector<char>> &grid, int **check, int x, int y, int line, int column) {
    check[x][y] = 1; 
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= line || y_t < 0 || y_t >= column || check[x_t][y_t] || grid[x_t][y_t] == '0') continue;
        FindLand(grid, check, x_t, y_t, line, column);
    }
}

int numIslands(vector<vector<char>> &grid) {
    int line = 0, column = 0;
    line = grid.size();
    if (line) column = grid[0].size();
    int **check = (int **) calloc(sizeof(int *), line + 5);
    for (int i = 0; i < line + 5; i++) {
        check[i] = (int *) calloc(sizeof(int), column + 5);
    }
    int cnt = 0;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '0') {
                check[i][j] = 1;
                continue;
            }
            if (grid[i][j] == '1' && !check[i][j]) {
                cnt++;
                FindLand(grid, check, i, j, line, column);
            }
        }
    }
    return cnt;
}

int main() {
    int line, column;
    cin >> line >> column;
    char c;
    vector<vector<char>> grid;
    for (int i = 0; i < line; i++) {
        vector<char> tmp;
        for (int j = 0; j < column; j++) {
            cin >> c;
            tmp.push_back(c);
        }
        grid.push_back(tmp);
    }
    int res = numIslands(grid);
    cout << res << endl;
    return 0;
}
