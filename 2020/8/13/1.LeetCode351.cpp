/*************************************************************************
	> File Name: 1.LeetCode351.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月13日 星期四 08时56分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int dir[20][2] = {
    1, 0,
    0, 1,
    -1, 0,
    0, -1,
    2, 0, 
    0, 2, 
    -2, 0,
    0, -2,
    1, 2, 
    1, -2, 
    -1, 2, 
    -1, -2, 
    2, 1, 
    -2, 1, 
    2, -1, 
    -2, -1
    2, 2, 
    2, -2, 
    -2, 2, 
    -2, -2
};

bool is_legal(int x, int y) {
    return (x >= 0) && (x < 3) && (y >= 0) && (y < 3);
}

void countPath(vector<vector<int>> &check, int x, int y, int cnt, int m, int n, int &ans) {
    if (!is_legal(x, y)) return ;
    if (cnt > n) return ;
    if (!check[x][y]) {
        check[x][y] = 1;
        if (cnt >= m) ans++;
        for (int i = 0; i < 20; i++) {
            countPath(check, x + dir[i][0], y + dir[i][1], cnt + 1, m, n, ans);
        }
        check[x][y] = 0;
    }
}

int numberOfPatterns(int m, int n) {
    vector<vector<int>> check(3, vector<int>(3, 0));
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            countPath(check, i, j, 0, m, n, ans);
        }
    }
    return ans;
}

int main() {
    return 0;
}
