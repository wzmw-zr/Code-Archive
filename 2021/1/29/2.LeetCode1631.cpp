/*************************************************************************
	> File Name: 2.LeetCode1631.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月29日 星期五 00时38分08秒
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
    int x, y;
    int val;
    Node() = default;
    Node(int x, int y, int val) : x(x), y(y), val(val) {}
    bool operator<(const struct Node &a) const {
        return this->val > a.val;
    }
};

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

typedef pair<int, int> PII;

int minimumEffortPath(vector<vector<int>>& heights) {
    int h = heights.size(), w = heights[0].size();
    map<PII, int> mp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) mp[PII(i, j)] = INT32_MAX;
    }
    priority_queue<Node> que;
    que.push(Node(0, 0, 0));
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        PII t(temp.x, temp.y);
        if (temp.val >= mp[t]) continue;
        mp[t] = temp.val;
        for (int i = 0; i < 4; i++) {
            int x_t = temp.x + dir[i][0];
            int y_t = temp.y + dir[i][1];
            if (x_t < 0 || x_t >= h || y_t < 0 || y_t >= w) continue;
            que.push(Node(x_t, y_t, max(temp.val, abs(heights[temp.x][temp.y] - heights[x_t][y_t]))));
        }
    }
    return mp[PII(h - 1, w - 1)];
}

int main() {
    return 0;
}
