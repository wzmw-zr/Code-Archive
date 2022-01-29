/*************************************************************************
	> File Name: 1.LeetCode1765.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月29日 星期六 09时26分32秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
    int x;
    int y;
    int height;

    Node() = default;
    Node(int x, int y, int height) : x(x), y(y), height(height) {}

    bool operator<(const struct Node &that) const {
        return this->height > that.height;
    }
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, 0));
    vector<vector<int>> check(m, vector<int>(n, 0));
    priority_queue<Node> que;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1) {
                que.push(Node(i, j, 0));
            }
        }
    }

    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (check[temp.x][temp.y]) {
            continue;
        }
        height[temp.x][temp.y] = temp.height;
        check[temp.x][temp.y] = 1;
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n || check[x][y] || isWater[x][y]) {
                continue;
            }
            que.push(Node(x, y, temp.height + 1));
        }
    }
    return height;
}

int main() {
    return 0;
}
