/*************************************************************************
	> File Name: 5.linear_programming.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月08日 星期一 21时26分22秒
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

void print(vector<vector<double>> &matrix) {
    for (auto x : matrix) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<double>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    while (1) {
        print(matrix);
        int ind = 0;
        for (int i = 0; i < n - 1; i++) {
            if (matrix[0][i] > matrix[0][ind]) ind = i;
        }
        if (matrix[0][ind] <= 0) {
            cout << matrix[0][n - 1] * -1 << endl;
            break;
        }
        cout << ind << endl;
        int row_id = 1;
        double min_upper = INT32_MAX;
        for (int i = 1; i < m; i++) {
            if (matrix[i][ind] <= 0) continue;
            double t = matrix[i][n - 1] / matrix[i][ind];
            if (t < min_upper) row_id = i, min_upper = t;
        }
        cout << row_id << " " << min_upper << endl;
        if (min_upper == INT32_MAX) break;

        double t = matrix[row_id][ind];
        for (int i = 0; i < n; i++) matrix[row_id][i] /= t;
        for (int i = 0; i < m; i++) {
            if ((matrix[i][ind] == 0) || (i == row_id)) continue;
            double p = matrix[i][ind];
            for (int j = 0; j < n; j++) matrix[i][j] -= p * matrix[row_id][j];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<double>> matrix(m + 1, vector<double>(n + m + 1, 0));
    for (int i = 0; i < n; i++) cin >> matrix[0][i];
    int s, t, v;
    for (int i = 1; i <= m; i++) {
        cin >> s >> t >> v;
        matrix[i][n + m] = v;
        for (int j = s - 1; j <= t - 1; j++) matrix[i][j] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (n + m + 1); j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    solve(matrix);
    return 0;
}
