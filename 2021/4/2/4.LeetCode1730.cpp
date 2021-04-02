/*************************************************************************
	> File Name: 4.LeetCode1730.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月02日 星期五 21时30分37秒
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
    int x;
    int y;
    int dis;
    Node() = default;
    Node(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int getFood(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int x, y;
    vector<vector<int>> check(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '*') continue;
            flag = 1;
            x = i, y = j;
            break;
        }
        if (flag) break;
    }
    queue<Node> que;
    que.push(Node(x, y, 0));
    check[x][y] = 1;
    while (!que.empty()) {
        Node temp = que.front();
        if (grid[temp.x][temp.y] == '#') return temp.dis;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x_t = temp.x + dir[i][0];
            int y_t = temp.y + dir[i][1];
            if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m || check[x_t][y_t] || grid[x_t][y_t] == 'X') continue;
            check[x_t][y_t] = 1;
            que.push(Node(x_t, y_t, temp.dis + 1));
        }
    }
    return -1;
}

int main() {
    return 0;
}
