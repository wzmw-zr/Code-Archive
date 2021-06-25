/*************************************************************************
	> File Name: 1.LeetCode773.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月26日 星期六 00时11分43秒
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

typedef vector<vector<int>> VVI;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int slidingPuzzle(vector<vector<int>>& board) {
    map<VVI, int> mp;
    VVI target({{1, 2, 3}, {4, 5, 0}});
    mp[board] = 0;
    queue<VVI> que;
    que.push(board);
    while (!que.empty()) {
        VVI temp = que.front();
        que.pop();
        if (temp == target) return mp[temp];
        int x = 0, y = 0;
        int cnt = mp[temp];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (temp[i][j] == 0) {
                    x = i, y = j;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            if ((x_t < 0) || (x_t >= 2) || (y_t < 0) || (y_t >= 3)) continue;
            swap(temp[x][y], temp[x_t][y_t]);
            if (!mp.count(temp)) {
                mp[temp] = cnt + 1;
                que.push(temp);
            }
            swap(temp[x][y], temp[x_t][y_t]);
        }
    }
    return -1;
}

int main() {
    return 0;
}
