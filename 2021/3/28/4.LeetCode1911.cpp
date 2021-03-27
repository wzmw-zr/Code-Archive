/*************************************************************************
	> File Name: 4.LeetCode1911.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 00时42分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &matrix, int n, int x, int y) {
    if (n <= 1) return ;
    for (int i = 0; i < n - 1; i++) {
        int a = matrix[x][y + i];
        int b = matrix[x + i][y + n - 1];
        int c = matrix[x + n - 1][y + n - 1 - i];
        int d = matrix[x + n - 1 - i][y];
        matrix[x][y + i] = d;
        matrix[x + i][y + n - 1] = a;
        matrix[x + n - 1][y + n - 1 - i] = b;
        matrix[x + n - 1 - i][y] = c;
    }
    dfs(matrix, n - 2, x + 1, y + 1);
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    dfs(matrix, n, 0, 0);
}

int main() {
    return 0;
}
