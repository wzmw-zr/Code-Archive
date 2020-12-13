/*************************************************************************
	> File Name: 2.LeetCode1868.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月13日 星期日 08时05分21秒
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

int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

int dfs(vector<vector<int>> &land, vector<vector<int>> &check, int x, int y) {
    if (x < 0 || x >= land.size() || y < 0 || y >= land[0].size()) return 0;
    if (check[x][y]) return 0;
    check[x][y] = 1;
    if (land[x][y]) return 0;
    int cnt = 1;
    for (int i = 0; i < 8; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        cnt += dfs(land, check, x_t, y_t);
    }
    return cnt;
}

vector<int> pondSizes(vector<vector<int>>& land) {
    int n = land.size(), m = land[0].size();
    vector<vector<int>> check(n, vector<int>(m, 0));
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = dfs(land, check, i, j);
            if (cnt) ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
