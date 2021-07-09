/*************************************************************************
	> File Name: 2.LeetCode51.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月09日 星期五 08时43分51秒
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

struct Node {
    int x;
    int y;

    Node() = default;
    Node(int x, int y) : x(x), y(y) {}
};

int check(vector<Node> &nodes, int x, int y) {
    for (auto node : nodes) {
        if (node.y == y) return 0;
        if ((x - node.x) == (y - node.y)) return 0;
        if ((x - node.x) == (node.y - y)) return 0;
    }
    return 1;
}

void dfs(vector<string> &chessboard, vector<Node> &nodes, int ind, int &n, vector<vector<string>> &ans) {
    if (ind == n) {
        ans.push_back(chessboard);
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!check(nodes, ind, i)) continue;
        chessboard[ind][i] = 'Q';
        nodes.push_back(Node(ind, i));
        dfs(chessboard, nodes, ind + 1, n, ans);
        chessboard[ind][i] = '.';
        nodes.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> chessboard(n, string(n, '.'));
    vector<Node> nodes;
    dfs(chessboard, nodes, 0, n, ans);
    return ans;
}

int main() {
    return 0;
}
