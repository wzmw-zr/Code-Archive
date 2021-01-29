/*************************************************************************
	> File Name: 2.LeetCode778.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 00时27分41秒
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
    int height;
    Node() = default;
    Node(int x, int y, int height) : x(x), y(y), height(height) {}  
    bool operator<(const struct Node &a) const {
        return this->height > a.height;
    }
};

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct UnionSet {
    int n;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = fa[b];
        n--;
    }
};

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<Node> que;
    UnionSet u(n * n);
    vector<vector<bool>> check(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            que.push(Node(i, j, grid[i][j]));
        }
    }
    int t = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        check[temp.x][temp.y] = true;
        t = temp.height;
        for (int i = 0; i < 4; i++) {
            int x_t = temp.x + dir[i][0];
            int y_t = temp.y + dir[i][1];
            if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n || !check[x_t][y_t]) continue;
            u.merge(temp.x * n + temp.y, x_t * n + y_t);
        }
        if (u.get(0) == u.get(n * n - 1)) break;
    }
    return t;
} 

int main() {
    return 0;
}
