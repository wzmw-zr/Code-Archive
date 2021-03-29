/*************************************************************************
	> File Name: 1.LeetCode74.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月30日 星期二 00时02分52秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (matrix[mid][n - 1] < target) l = mid + 1;
        else r = mid;
    }
    if (matrix[l][0] > target || matrix[l][n - 1] < target) return false;
    int x = 0, y = n - 1;
    while (x < y) {
        int mid = (x + y) / 2;
        if (matrix[l][mid] == target) return true;
        if (matrix[l][mid] < target) x = mid + 1;
        else y = mid - 1;
    }
    return matrix[l][x] == target;
}

int main() {
    return 0;
}
