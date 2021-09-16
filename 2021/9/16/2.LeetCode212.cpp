/*************************************************************************
	> File Name: 2.LeetCode212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月16日 星期四 12时04分36秒
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
    bool end;
    vector<Node *> next;

    Node() : end(false), next(26, nullptr) {}
    Node(int end) : end(false), next(26, nullptr) {}
};

struct Trie {
    Node *root;

    Trie() : root(new Node()) {}

    void insert(string s) {
        Node *p = root;
        for (char c : s) {
            if (!p->next[c - 'a']) p->next[c - 'a'] = new Node();
            p = p->next[c - 'a'];
        }
        p->end = true;
    }
};

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void dfs(Node *root, vector<vector<char>> &board, vector<vector<int>> &check, int x, int y, int &m, int &n, unordered_set<string> &st, string s) {
    if (!root) return ;
    if (root->end) st.insert(s);
    if (x < 0 || x >= m || y < 0 || y >= n || check[x][y] || !root->next[board[x][y] - 'a']) return ;
    s += board[x][y];
    check[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        dfs(root->next[board[x][y] - 'a'], board, check, x_t, y_t, m, n, st, s);
    }
    check[x][y] = 0;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (string &word : words) trie.insert(word);
    int m = board.size(), n = board[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    unordered_set<string> st;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(trie.root, board, check, i, j, m, n, st, "");
        }
    }
    vector<string> ans;
    for (string s : st) ans.push_back(s);
    return ans;
}

int main() {
    return 0;
}
