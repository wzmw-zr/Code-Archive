/*************************************************************************
	> File Name: 2.LeetCode5793.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月10日 星期六 22时34分24秒
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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size(), n = maze[0].size();
    map<PII, int> mp;
    queue<PII> que;
    mp[PII(entrance[0], entrance[1])] = 0;
    que.push(PII(entrance[0], entrance[1]));
    while (!que.empty()) {
        PII temp = que.front();
        que.pop();
        auto [x, y] = temp;
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            PII coord(x_t, y_t);
            if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || maze[x_t][y_t] == '+' || mp.count(coord)) continue;
            if (x_t == 0 || x_t == (m - 1) || y_t == 0 || y_t == (n - 1)) return mp[temp] + 1;
            mp[coord] = mp[temp] + 1;
            que.push(coord);
        }
    }
    return -1;
}

int main() {
    return 0;
}
