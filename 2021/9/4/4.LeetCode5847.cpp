/*************************************************************************
	> File Name: 4.LeetCode5847.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月04日 星期六 22时48分19秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size(), n = land[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!land[i][j] || check[i][j]) continue;
            int h = 0, w = 0;
            while ((i + h < m) && land[i + h][j]) h++;
            while ((j + w < n) && land[i][j + w]) w++;
            ans.push_back({i, j, i + h - 1, j + w - 1});
            for (int x = i; x < i + h; x++) {
                for (int y = j; y < j + w; y++) check[x][y] = 1;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
