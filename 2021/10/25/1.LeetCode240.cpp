/*************************************************************************
	> File Name: 1.LeetCode240.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月25日 星期一 08时16分06秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int bs_first_ge(vector<int> &arr, int r, int target) {
    int l = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int r = n - 1;
    for (int i = 0; i < m; i++) {
        r = bs_first_ge(matrix[i], r, target);
        if (matrix[i][r] == target) return true;
    }
    return false;
}

int main() {
    return 0;
}
