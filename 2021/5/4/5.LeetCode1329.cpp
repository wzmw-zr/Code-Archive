/*************************************************************************
	> File Name: 5.LeetCode1329.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月04日 星期二 22时27分09秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sort_ops(vector<vector<int>> &mat, int x, int y) {
    int m = mat.size(), n = mat[0].size();
    int ind = 0;
    vector<int> vals;
    while ((x + ind < m) && (y + ind < n)) {
        vals.push_back(mat[x + ind][y + ind]);
        ind++;
    }
    sort(vals.begin(), vals.end());
    ind = 0;
    while ((x + ind < m) && (y + ind < n)) {
        mat[x + ind][y + ind] = vals[ind];
        ind++;
    }
}

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < n; i++) 
        sort_ops(mat, 0, i);
    for (int i = 1; i < m; i++)
        sort_ops(mat, i, 0);
    return mat;
}

int main() {
    return 0;
}
