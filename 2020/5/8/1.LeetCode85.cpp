/*************************************************************************
	> File Name: 1.LeetCode85.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月08日 星期五 07时17分48秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Node {
    int h, w;
};

int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    Node dp[matrix.size() + 5][matrix[0].size() + 5];
    memset(dp, 0, sizeof(dp));
    int msize = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[0][i] == '0') continue;
        if (i == 0) {
            dp[0][i] = {1, 1};
            msize = 1;
        }
        else {
            Node tmp = dp[0][i - 1];
            dp[0][i] = {1, tmp.w + 1};
            msize = max(msize, dp[0][i].w);
        }
    }
    for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][0] == '0') continue;
        Node tmp = dp[i - 1][0];
        dp[i][0] = {tmp.h + 1, 1};
        msize = max(msize, dp[i][0].h);
    }
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '0') continue;
            Node x = dp[i - 1][j], y = dp[i][j - 1], z = dp[i - 1][j - 1];
            if (x.h == 0 && z.h == 0) dp[i][j] = {1, y.w + 1};
            else if (y.w == 0 && z.w == 0) dp[i][j] = {x.h + 1, 1};
            else if (z.h == 0 && z.w == 0) {
                if (x.h > y.w) msize = max(msize, x.h + 1), dp[i][j] = {x.h + 1, 1};
                else msize = max(msize, y.w + 1), dp[i][j] = {1, y.w + 1};
            }
            else dp[i][j] = {min(x.h, z.h) + 1, min(y.w, z.w) + 1};
            msize = max(msize, dp[i][j].h * dp[i][j].w);
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << "(" << dp[i][j].h << "," <<  dp[i][j].w << ") ";
        }
        cout << endl;
    }
    return msize;
}

int main() {
    int h, w;
    vector<vector<char>> matrix;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        vector<char> tmp;
        char c;
        for (int j = 0; j < w; j++) {
            cin >> c;
            tmp.push_back(c);
        }
        matrix.push_back(tmp);
    }
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
