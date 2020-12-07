/*************************************************************************
	> File Name: 1.LeetCode861.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月07日 星期一 06时58分47秒
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

int get_value(vector<vector<int>> &A) {
    int ans = 0;
    for (auto &x : A) {
        int temp = 0;
        for (auto &y : x) temp = (temp << 1) | y;
        ans += temp;
    }
    return ans;
}

void change_row(vector<vector<int>> &A, int row) {
    for (int i = 0; i < A[i].size(); i++) A[row][i] ^= 1;
}

void change_column(vector<vector<int>> &A, int column) {
    for (int i = 0; i < A.size(); i++) A[i][column] ^= 1;
}

int matrixScore(vector<vector<int>>& A) {
    int ans = get_value(A);
    int n = A.size(), m = A[0].size();
    while (1) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            change_row(A, i);
            int temp = get_value(A);
            if (temp <= ans) change_row(A, i);
            else ans = temp, flag = 1;
        }
        if (flag) continue;
        for (int i = 0; i < m; i++) {
            change_column(A, i);
            int temp = get_value(A);
            if (temp <= ans) change_column(A, i);
            else ans = temp, flag = 1;
        }
        if (flag) continue;
        break;
    }
    return ans;
}

int main() {
    return 0;
}
