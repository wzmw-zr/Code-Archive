/*************************************************************************
	> File Name: 1.LeetCode85.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月26日 星期六 07时25分39秒
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

typedef pair<int, int> PII;

void init(vector<vector<char>> &matrix, vector<vector<int>> &pre) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++) pre[i][0] = matrix[i][0] - '0';
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            pre[i][j] = (matrix[i][j] - '0') ? pre[i][j - 1] + 1 : 0;
        }
    }
}

int get_cnt(vector<vector<int>> &pre, int x, int y) {
    int rows = pre.size();
    int cols = pre[0].size();
    int len = pre[x][y];
    int cnt = len;
    for (int i = x + 1; i < rows; i++) {
        if (!pre[i][y]) break;
        len = min(len, pre[i][y]);
        cnt = max(cnt, len * (i - x + 1));
    }
    return cnt;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (!rows) return 0;
    int cols = matrix[0].size();
    if (!cols) return 0;
    int ans = 0;;
    vector<vector<int>> pre(rows, vector<int>(cols, 0));
    init(matrix, pre);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(matrix[i][j] - '0')) continue;
            ans = max(ans, get_cnt(pre, i, j));
        }
    }
    return ans;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> matrix;
    for (int i = 0; i < rows; i++) matrix.push_back(vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cin >> matrix[i][j];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
