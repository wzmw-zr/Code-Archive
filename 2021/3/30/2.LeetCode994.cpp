/*************************************************************************
	> File Name: 2.LeetCode994.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月30日 星期二 00时15分27秒
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

struct Node {
    int t;
    int x, y;
    Node() = default;
    Node(int x, int y, int t) : x(x), y(y), t(t) {}
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> check(n, vector<int>(m, 0));
    int cnt = 0;
    int t = 0;
    queue<Node> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                que.push(Node(i, j, 0));
                check[i][j] = 1;
            }
            cnt += grid[i][j] == 1 ? 1 : 0;
        }
    }
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        t = max(t, temp.t);
        for (int i = 0; i < 4; i++) {
            int x_t = temp.x + dir[i][0];
            int y_t = temp.y + dir[i][1];
            if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m) continue;
            if (check[x_t][y_t] || grid[x_t][y_t] == 0) continue;
            check[x_t][y_t] = 1;
            cnt--;
            que.push(Node(x_t, y_t, temp.t + 1));
        }
    }
    return cnt == 0 ? t : -1;
}

int main() {
    return 0;
}
