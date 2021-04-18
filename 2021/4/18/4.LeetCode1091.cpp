/*************************************************************************
	> File Name: 4.LeetCode1091.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月18日 星期日 22时08分58秒
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

int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0]) return -1;
    int n = grid.size();
    vector<vector<int>> check(n, vector<int>(n, 0));
    queue<Node> que;
    que.push(Node(0, 0, 1));
    check[0][0] = 1;
    while (!que.empty()) {
        Node temp = que.front();
        if (temp.x == n - 1 && temp.y == n - 1) return temp.dis;
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x_t = temp.x + dir[i][0];
            int y_t = temp.y + dir[i][1];
            if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n || check[x_t][y_t] || grid[x_t][y_t]) continue;
            check[x_t][y_t] = 1;
            que.push(Node(x_t, y_t, temp.dis + 1));
        }
    }
    return -1;
}

int main() {
    return 0;
}
