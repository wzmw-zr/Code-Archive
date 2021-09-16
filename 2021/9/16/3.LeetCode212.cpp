/*************************************************************************
	> File Name: 3.LeetCode212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月16日 星期四 13时47分34秒
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

// TLE
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void dfs(vector<vector<char>> &board, vector<vector<int>> &check, int x, int y, int &m, int &n, string s, unordered_set<string> &st, vector<string> &ans) {
    if (x < 0 || x >= m || y < 0 || y >= n || check[x][y] || s.size() > 10) return ;
    s += board[x][y];
    if (st.count(s)) {
        ans.push_back(s);
        st.erase(s);
    }
    check[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || check[x_t][y_t]) continue;
        dfs(board, check, x_t, y_t, m, n, s, st, ans);
    }
    check[x][y] = 0;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_set<string> st;
    for (auto &&word : words) st.insert(move(word));
    int m = board.size(), n = board[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    vector<string> ans;
    string t = "";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(board, check, i, j, m, n, "", st, ans);
        }
    }
    return ans;
}

int main() {
    return 0;
}
