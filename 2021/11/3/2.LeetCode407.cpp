/*************************************************************************
	> File Name: 2.LeetCode407.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月03日 星期三 14时18分10秒
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
#include <tuple>
using namespace std;

struct Node {
    int x, y, h;

    Node() = default;
    Node(int x, int y, int h) : x(x), y(y), h(h) {}

    bool operator<(const struct Node &that) const {
        return this->h > that.h;
    }
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    priority_queue<Node> que;
    for (int i = 0; i < n; i++) que.push(Node(0, i, heightMap[0][i])), que.push(Node(m - 1, i, heightMap[m - 1][i]));
    for (int i = 0; i < m; i++) que.push(Node(i, 0, heightMap[i][0])), que.push(Node(i, n - 1, heightMap[i][n - 1]));
    vector<vector<int>> check(m, vector<int>(n, 0));
    int ans = 0;
    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        if (check[temp.x][temp.y]) continue;
        check[temp.x][temp.y] = 1;
        ans += temp.h - heightMap[temp.x][temp.y];
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n || check[x][y]) continue;
            que.push(Node(x, y, max(temp.h, heightMap[x][y])));
        }
    }
    return ans;
}

int main() {
    return 0;
}
