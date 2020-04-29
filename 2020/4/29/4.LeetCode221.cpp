/*************************************************************************
	> File Name: 4.LeetCode221.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 15时54分12秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int line = matrix.size(), col = matrix[0].size();
    int mmap[line + 5][col + 5];
    memset(mmap, 0, sizeof(mmap));
    int ans = 0;
    for (int i = 0; i < col; i++) {
        mmap[0][i] = matrix[0][i];
        ans |= mmap[0][i];
    }
    for (int i = 0; i < line; i++) {
        mmap[i][0] = matrix[i][0];   
        ans |= mmap[i][0];
    }
    for (int i = 1; i < line; i++) {
        for (int j = 1; j < col; j++) {
            if (!matrix[i][j]) mmap[i][j] = 0;
            else {
                int tmp = min(mmap[i][j - 1], mmap[i - 1][j]);
                tmp = min(tmp, mmap[i - 1][j - 1]);
                mmap[i][j] = min(mmap[i - 1][j], min(mmap[i][j - 1], mmap[i - 1][j - 1])) + 1;    
                ans = max(mmap[i][j], ans);
            }
        }
    }
    return ans * ans;
}

int main() {
    int n, m;
    char num;
    vector<vector<char>> matrix;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<char> tmp;
        for (int j = 0; j < m; j++) {
            cin >> num;
            tmp.push_back(num - '0');
        }
        matrix.push_back(tmp);
    }
    cout << maximalSquare(matrix) << endl;
    return 0;
}
