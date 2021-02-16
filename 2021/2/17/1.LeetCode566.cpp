/*************************************************************************
	> File Name: 1.LeetCode566.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月17日 星期三 00时01分39秒
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

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int n = nums.size(), m = nums[0].size();
    if (r * c != n * m) return nums;
    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;  j++) {
            int ind = i * m + j;
            int row = ind / c, col = ind % c;
            ans[row][col] = nums[i][j];
        }
    }
    return ans;
}

int main() {
    return 0;
}
