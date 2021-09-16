/*************************************************************************
	> File Name: 1.LeetCode212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月16日 星期四 09时02分04秒
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

// WA
struct Node {
    bool end;
    unordered_map<char, Node *> next;

    Node() = default;
    Node(bool end = false) : end(end), next(unordered_map<char, Node *>()) {}
};

struct Trie {
    Node *root;

    Trie() : root(new Node(false)) {}

    void insert(string s) {
        Node *p = root;
        for (char c : s) {
            if (!p->next.count(c)) p->next[c] = new Node(false);
            p = p->next[c];
        }
        p->end = true;
    }
};

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void dfs(Node *root, vector<vector<char>> &board, int x, int y, int &m, int &n, unordered_set<string> &st, string s) {
    if (!root || x < 0 || x >= m || y < 0 || y >= n) return ;
    if (root->end) st.insert(s);
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || !root->next.count(board[x_t][y_t])) continue;
        dfs(root->next[board[x_t][y_t]], board, x_t, y_t, m, n, st, s + board[x_t][y_t]);
    }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (auto word : words) trie.insert(word);
    int m = board.size(), n = board[0].size();
    unordered_set<string> st;
    string t = "";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!trie.root->next.count(board[i][j])) continue;
            dfs(trie.root->next[board[i][j]], board, i, j, m, n, st, t + board[i][j]);
        }
    }
    vector<string> ans;
    for (auto s : st) ans.push_back(s);
    return ans;
}

int main() {
    return 0;
}
