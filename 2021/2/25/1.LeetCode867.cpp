/*************************************************************************
	> File Name: 1.LeetCode867.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月25日 星期四 00时04分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans[j][i] = matrix[i][j];
    }
    return ans;
}

int main() {
    return 0;
}
