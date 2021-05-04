/*************************************************************************
	> File Name: 2.LeetCode2023.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月05日 星期三 00时36分46秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int bs_first_ge(vector<vector<int>> &matrix, int ind, int l, int r, int &target) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (matrix[mid][ind] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int l = 0, r = m - 1;
    for (int i = 0; i < n; i++) {
        r = bs_first_ge(matrix, i, l, r, target);
        if (matrix[r][i] == target) 
            return true;
    }
    return false;
}

int main() {
    return 0;
}
