/*************************************************************************
	> File Name: 1.LeetCode959.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月25日 星期一 00时01分48秒
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

// Wrong Answer

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int ans = 1;
    vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == ' ') continue;
            int x_1, y_1, x_2, y_2;
            if (grid[i][j] == '\\') x_1 = i, y_1 = j, x_2 = i + 1, y_2 = j + 1;
            else x_1 = i, y_1 = j + 1, x_2 = i + 1, y_2 = j;
            if ((x_1 == 0 || x_1 == n || y_1 == 0 || y_1 == n) && (x_2 == 0 || x_2 == n || y_2 == 0 || y_2 == n)) {
                ans++;
                continue;
            }
            if (x_1 == 0 || x_1 == n || y_1 == 0 || y_1 == n) {
                if (check[x_2][y_2]) ans++;
                check[x_2][y_2] = true;
                continue;
            }
            if (x_2 == 0 || x_2 == n || y_2 == 0 || y_2 == n) {
                if (check[x_1][y_1]) ans++;
                check[x_1][y_1] = true;
                continue;
            }
            if (check[x_1][y_1] && check[x_2][y_2]) ans++;
            check[x_1][y_1] = check[x_2][y_2] = true;
            continue;
        }
    }
    return ans;
}

int main() {
    return 0;
}
