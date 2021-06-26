/*************************************************************************
	> File Name: 1.LeetCode909.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月27日 星期日 00时03分14秒
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

typedef pair<int, int> PII;

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    map<int, PII> pos;
    int ind = 1;
    int dir = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (dir == 0) {
            for (int j = 0; j < n; j++) pos[ind++] = PII(i, j);
        } else {
            for (int j = n - 1; j >= 0; j--) pos[ind++] = PII(i, j);
        }
        dir = !dir;
    }
    map<int, int> mp;
    queue<int> que;
    que.push(1);
    mp[1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        if (temp == n * n) return mp[temp];
        for (int i = 1; i <= 6; i++) {
            PII coord = pos[temp + i];
            int x = coord.first, y = coord.second;
            int next = board[x][y] == -1 ? temp + i : board[x][y];
            if (mp.count(next)) continue;
            mp[next] = mp[temp] + 1;
            que.push(next);
        }
    }
    return -1;
}

int main() {
    return 0;
}
