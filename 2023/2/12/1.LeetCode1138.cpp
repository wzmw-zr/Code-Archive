/*************************************************************************
	> File Name: 1.LeetCode1138.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月12日 星期日 19时44分05秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
  int x;
  int y;
  string s;

  Node() = default;
  Node(int x, int y, string s) : x(x), y(y), s(s) {}
};

using PII = pair<int, int>;

unordered_map<char, PII> dirs = {
  {'L', PII(0, -1)},
  {'R', PII(0, 1)},
  {'U', PII(-1, 0)},
  {'D', PII(1, 0)},
};

unordered_map<char, string> bfs(vector<string> &board, int x, int y) {
  int n = board.size(), m = board[0].size();
  queue<Node> que;
  unordered_map<char, string> mp;
  que.push(Node(x, y, ""));
  mp[board[x][y]] = "!";
  while (!que.empty()) {
    int cnt = que.size();
    for (int i = 0; i < cnt; i++) {
      Node t = que.front();
      que.pop();
      int x1 = t.x, y1 = t.y;
      string s = t.s;
      // mp[board[x][y]] = s + "!";
      for (auto && [c, offset] : dirs) {
        int x_t = x1 + offset.first;
        int y_t = y1 + offset.second;
        if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m || board[x_t][y_t] == ' ' || mp.count(board[x_t][y_t]))
          continue;
        mp[board[x_t][y_t]] = s + c + '!';
        que.push(Node(x_t, y_t, s + c));
      }
    }
  }
  return mp;
}

string alphabetBoardPath(string target) {
  vector<string> board({
    "abcde",
    "fghij",
    "klmno",
    "pqrst",
    "uvwxy",
    "z    ",
  });
  unordered_map<char, unordered_map<char, string>> mp;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == ' ')
        continue;
      mp[board[i][j]] = bfs(board, i, j);
    }
  }
  string ans = "";
  char ch = 'a';
  for (char c : target) {
    ans += mp[ch][c];
    ch = c;
  }
  return ans;
}

int main() {
  return 0;
}
