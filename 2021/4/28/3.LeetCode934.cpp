/*************************************************************************
	> File Name: 3.LeetCode934.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月28日 星期三 00时56分06秒
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

void get_one_value_position(vector<vector<int>> &A, int &x, int &y) {
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (!A[i][j]) continue;
            flag = 1;
            x = i, y = j;
            break;
        }
        if (flag) break;
    }
}

struct Node {
    int x, y;
    int dis;
    Node() = default;
    Node(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

typedef pair<int, int> PII;

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void dfs(vector<vector<int>> &A, vector<vector<int>> &check, int x, int y, queue<Node> &surround) {
    int n = A.size(), m = A[0].size();
    queue<PII> que;
    que.push(PII(x, y));
    check[x][y] = 1;
    while (!que.empty()) {
        auto temp = que.front();
        auto &&[x, y]  = temp;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m || check[x_t][y_t]) continue;
            if (A[x_t][y_t]) que.push(PII(x_t, y_t));
            else surround.push(Node(x_t, y_t, 1));
            check[x_t][y_t] = 1;
        }
    }
}

int shortestBridge(vector<vector<int>>& A) {
    int n = A.size(), m = A[0].size();
    int x, y;
    get_one_value_position(A, x, y);
    vector<vector<int>> check(n, vector<int>(m, 0));
    queue<Node> que;
    dfs(A, check, x, y, que);
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x_t = temp.x + dir[i][0];
            int y_t = temp.y + dir[i][1];
            if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m || check[x_t][y_t]) continue;
            if (A[x_t][y_t]) return temp.dis;
            check[x_t][y_t] = 1;
            que.push(Node(x_t, y_t, temp.dis + 1));
        }
    }
    return -1;
}

int main() {
    return 0;
}
