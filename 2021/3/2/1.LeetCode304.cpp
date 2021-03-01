/*************************************************************************
	> File Name: 1.LeetCode304.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月02日 星期二 00时03分16秒
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

class NumMatrix {
public:
    vector<vector<int>> pre_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return ;
        int n = matrix.size(), m = matrix[0].size();
        pre_sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                pre_sum[i + 1][j + 1] = matrix[i][j] + pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2 + 1][col2 + 1] - pre_sum[row2 + 1][col1] - pre_sum[row1][col2 + 1] + pre_sum[row1][col1];
    }
};


int main() {
    return 0;
}
