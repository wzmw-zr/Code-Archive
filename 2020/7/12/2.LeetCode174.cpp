/*************************************************************************
	> File Name: 2.LeetCode174.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月12日 星期日 07时28分05秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

void calculateMinimumHP(vector<vector<int>> &dungeon, int x, int y, int sum, int res, int &ans) {
    if (x >= dungeon.size() || y >= dungeon[0].size()) return ;
    if (x == dungeon.size() - 1 && y == dungeon[0].size() - 1) {
        res = min(res, sum);
        sum += dungeon[x][y];
        res = min(res, sum);
        ans = max(ans, res);
        return ;
    }
    res = min(res, sum);
    calculateMinimumHP(dungeon, x + 1, y, sum + dungeon[x][y], res, ans);
    calculateMinimumHP(dungeon, x, y + 1, sum + dungeon[x][y], res, ans);
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.size() == 0) return 1;
    if (dungeon[0].size() == 0) return 1;

    int ans = -0x3f3f3f3f;
    calculateMinimumHP(dungeon, 0, 0, 0, 0, ans);
    if (ans <= 0) ans = -ans + 1;
    else ans = 1;
    return ans;
}


int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dungeon(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            dungeon[i][j] = x;
        }
    }
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
