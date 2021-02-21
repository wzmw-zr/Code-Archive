/*************************************************************************
	> File Name: 1.LeetCode766.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月22日 星期一 00时04分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < m; i++) {
        int step = 0;
        while (1) {
            int x = step, y = i + step;
            if (x >= n || y >= m) break;
            if (matrix[0][i] != matrix[x][y]) return false;
            step++;
        }
    }
    for (int i = 1; i < n; i++) {
        int step = 0;
        while (1) {
            int x = i + step, y = step;
            if (x >= n || y >= m) break;
            if (matrix[i][0] != matrix[x][y]) return false;
            step++;
        }
    }
    return true;
}
int main() {
    return 0;
}
