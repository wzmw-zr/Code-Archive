/*************************************************************************
	> File Name: 1.LeetCode73.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月21日 星期日 00时01分46秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef pair<int, int> PII;

void setZeroes(vector<vector<int>>& matrix) {
    vector<PII> pos;
    int n = matrix.size();
    if (n == 0) return ;
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) continue;
            pos.push_back(PII(i, j));
        }
    }
    for (auto &&[x, y] : pos) {
        for (int i = 0; i < m; i++) matrix[x][i] = 0;
        for (int i = 0; i < n; i++) matrix[i][y] = 0;
    }
}

int main() {
    return 0;
}
