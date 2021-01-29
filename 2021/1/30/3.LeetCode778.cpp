/*************************************************************************
	> File Name: 3.LeetCode778.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 00时54分42秒
 ************************************************************************/

#include<iostream>
#include<string>
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

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<Node> que;
    vector<vector<bool>> check(n, vector<bool>(n, false));
    que.push(Node(0, 0, grid[0][0]));
    int ans = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.x == n - 1 && temp.y == n - 1) {
            ans = temp.val;
            break;
        }
        check[temp.x][temp.y] = true;
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || x >= n || y < 0 || y >= n || check[x][y]) continue;
            que.push(Node(x, y, max(temp.val, grid[x][y])));
        }
    }
    return ans;
}

int main() {
    return 0;
}
