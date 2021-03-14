/*************************************************************************
	> File Name: 1.LeetCode54.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 00时02分23秒
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

void dfs(vector<int> &ans, vector<vector<int>> &matrix, int x, int y, int m, int n) {
    if (m == 0 || n == 0) return ;
    if (m == 1) {
        for (int i = 0; i < n; i++) ans.push_back(matrix[x][y + i]);
        return ;
    }
    if (n == 1) {
        for (int i = 0; i < m; i++) ans.push_back(matrix[x + i][y]);
        return ;
    }
    for (int i = 0; i < n; i++) ans.push_back(matrix[x][y + i]);
    for (int i = 1; i < m; i++) ans.push_back(matrix[x + i][y + n - 1]);
    for (int i = n - 2; i >= 0; i--) ans.push_back(matrix[x + m - 1][y + i]);
    for (int i = m - 2; i > 0; i--) ans.push_back(matrix[x + i][y]);
    dfs(ans, matrix, x + 1, y + 1, m - 2, n - 2);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = 0;
    vector<int> ans;
    dfs(ans, matrix, x, y, m, n);
    return ans;
}

int main() {
    return 0;
}
