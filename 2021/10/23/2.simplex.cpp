/*************************************************************************
	> File Name: 2.simplex.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月23日 星期六 18时31分49秒
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

using PII = pair<int, int>;

bool check(vector<vector<double>> &matrix, int &y) {
    int l = matrix[0].size();
    double mmax = INT32_MIN;
    for (int i = 0; i < l - 1; i++) {
        if (mmax >= matrix[0][i]) continue;
        mmax = matrix[0][i];
        y = i;
    }
    return mmax > 0;
}

void pivot(vector<vector<double>> &matrix, int x, int y) {
    int m = matrix.size();
    int n = matrix[0].size();
    double norm = matrix[x][y];
    for (auto &&e : matrix[x]) e /= norm;
    for (int i = 0; i < m; i++) {
        if (i != x && matrix[i][y] != 0) {
            double t = matrix[i][y];
            for (int j = 0; j < n; j++) matrix[i][j] -= t * matrix[x][j];
        }
    }
}

double solve(vector<vector<double>> &matrix) {
    int n = matrix[0].size();
    int m = static_cast<int>(matrix.size()) - 1;
    int x, y;
    while (check(matrix, y)) {
        double mmin = INT32_MAX;
        for (int i = 1; i <= m; i++) {
            if (matrix[i][y] <= 0) continue;
            double t = matrix[i][n - 1] / matrix[i][y];
            if (t >= mmin) continue;
            mmin = t;
            x = i;
        }
        pivot(matrix, x, y);
    }
    return *(matrix[0].rbegin()) * -1.0;
}

void print_matrix(vector<vector<double>> &matrix) {
    for (auto line : matrix) {
        for (auto x : line) cout << x << " ";
        cout << endl;
    }
}

int main() {
    // n : number of parameters (original non-axis parameters).
    // m : number of constraints.
    int n, m;
    cin >> n >> m;
    vector<vector<double>> matrix(m + 1, vector<double>(n + m + 1, 0));
    // first line : coefficients of each parameters 
    // format : a0 a1 a2 a3
    // meaning : object function z = a0 * x0 + a1 * x1 + a2 * x2 + a3 * x3.
    for (int i = 0; i < n; i++) cin >> matrix[0][i];
    // following `@param m` lines : coefficients of each parameter and constant in the constraint.
    // format : a0 a1 a2 a3 b
    // meaning : a0 * x1 + a1 * x1 + a2 * x2 + a3 * x3 <= b
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
        cin >> matrix[i][n + m];
        matrix[i][n + i - 1] = 1;
    }
    print_matrix(matrix);
    cout << solve(matrix) << endl;
    print_matrix(matrix);
    return 0;
}
