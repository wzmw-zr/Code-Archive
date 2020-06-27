/*************************************************************************
	> File Name: 1.LeetCode1139.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月27日 星期六 07时11分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int down_length(int x, int y, vector<vector<int>> &grid) {
    int cnt = 0;
    for (int i = x; i < grid.size() && grid[i][y]; i++) cnt++;
    return cnt;
}

int right_length(int x, int y, vector<vector<int>> &grid) {
    int cnt = 0;
    for (int i = y; i < grid[0].size() && grid[x][i]; i++) cnt++;
    return cnt;
}

int check(int x, int y, vector<vector<int>> &grid) {
    int x_left_one_cnt = 0, y_below_one_cnt = 0;
    for (int i = y; i < grid[0].size() && grid[x][i]; i++) 
        x_left_one_cnt++;
    //cout << x_left_one_cnt << endl;
    for (int i = x; i < grid.size() && grid[i][y]; i++)
        y_below_one_cnt++;
    //cout << y_below_one_cnt << endl;
    //cout << y_below_one_cnt << endl;
    int res = min(x_left_one_cnt, y_below_one_cnt);
    if (res == 0) return 0;
    for (int i = res; i > 0; i--) {
        int r_l = down_length(x, y + i - 1, grid);
        int b_l = right_length(x + i - 1, y, grid);
        //cout << r_l << " " << b_l << endl << endl;
        if (min(r_l, b_l) < i) continue;
        res = i;
        return res;
    }
    return 0;
}

int largest1BorderedSquare(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            int tmp = check(i, j, grid);
            res = max(res, tmp);
        }
    }
    return res * res;
}

int main() {
    int h, w;
    cin >> h >> w;;
    vector<vector<int>> grid;
    for (int i = 0; i < h; i++) {
        vector<int> tmp;
        for (int j = 0; j < w; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        grid.push_back(tmp);
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << largest1BorderedSquare(grid) << endl;
    return 0;
}
