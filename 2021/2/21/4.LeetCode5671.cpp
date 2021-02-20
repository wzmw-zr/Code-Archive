/*************************************************************************
	> File Name: 4.LeetCode5671.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月21日 星期日 01时05分06秒
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

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct Node {
    int x;
    int y;
    int height;
    Node() = default;
    Node(int x, int y, int height) : x(x), y(y), height(height) {}
    bool operator<(const struct Node &a) const {
        return this->height > a.height;
    }
};

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int h = isWater.size(), w = isWater[0].size();
    priority_queue<Node> que;
    vector<vector<int>> check(h, vector<int>(w, 0));
    vector<vector<int>> ans(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!isWater[i][j]) continue;
            que.push(Node(i, j, 0));
            check[i][j] = 1;
        }
    }
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        int x = temp.x, y = temp.y;
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            if (x_t < 0 || x_t >= h || y_t < 0 || y_t >= w || check[x_t][y_t]) continue;
            check[x_t][y_t] = 1;
            ans[x_t][y_t] = temp.height + 1;
            que.push(Node(x_t, y_t, temp.height + 1));
        }
    }
    return ans;
}

int main() {
    return 0;
}
