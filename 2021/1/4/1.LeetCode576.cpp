/*************************************************************************
	> File Name: 1.LeetCode576.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月04日 星期一 06时21分46秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int check[55][55][55];
int val[55][55][55];

int dfs(int m, int n, int N, int x, int y) {
    if (N < 0) return 0;
    if (x < 0 || x >= m || y < 0 || y >= n) return 1;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (check[x_t][y_t][N - 1]) ans += val[x_t][y_t][N - 1];
        else ans += dfs(m, n, N - 1, x_t, y_t);
        ans %= 1000000007;
    }
    check[x][y][N] = 1;
    val[x][y][N] = ans;
    return ans;
}

int findPaths(int m, int n, int N, int i, int j) {
    memset(check, 0, sizeof(check));
    memset(val, 0, sizeof(val));
    int ans = dfs(m, n, N, i, j);
    return ans;
}

int main() {
    int m, n, N, i, j;
    cin >> m >> n >> N >> i >> j;
    cout << findPaths(m, n, N, i, j) << endl;
    return 0;
}
