/*************************************************************************
	> File Name: 2.LeetCode5776.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月06日 星期日 10时30分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void rotate(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = n - 1 - j;
            int y = i;
            temp[x][y] = mat[i][j];
        }
    }
    mat = temp;
}

bool isSame(vector<vector<int>> &mat, vector<vector<int>> &target) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j]) return false;
        }
    }
    return true;
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int i = 0; i < 4; i++) {
        rotate(mat);
        if (isSame(mat, target)) return true;
    }
    return false;
}

int main() {
    return 0;
}
