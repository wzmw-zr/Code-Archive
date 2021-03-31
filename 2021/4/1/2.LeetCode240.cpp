/*************************************************************************
	> File Name: 2.LeetCode240.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月01日 星期四 00时20分36秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (matrix[i][mid] == target) return true;
            if (matrix[i][mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        if (matrix[i][l] == target) return true;
    }
    return false;
}

int main() {
    return 0;
}
