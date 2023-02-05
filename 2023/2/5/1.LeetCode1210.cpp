/*************************************************************************
	> File Name: 1.LeetCode1210.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月05日 星期日 14时42分22秒
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
  vector<int> pos;
  int step;

  Node() = default;
  Node(int x1, int y1, int x2, int y2, int step) : pos(vector<int>({x1, y1, x2, y2})), step(step) {}
};

int minimumMoves(vector<vector<int>>& grid) {
  int n = grid.size();
  queue<Node> que;
  set<vector<int>> st;
  que.push(Node(0, 0, 0, 1, 0));
  st.insert({0, 0, 0, 1});
  while (!que.empty()) {
    Node temp = que.front();
    que.pop();
    int x1 = temp.pos[0], y1 = temp.pos[1], x2 = temp.pos[2], y2 = temp.pos[3], step = temp.step;
    if ((x1 == n - 1) && (y1 == n - 2) && (x2 == n - 1) && (y2 == n - 1))
      return step;
    if (x1 == x2) {
      if ((y2 < n - 1) && !grid[x1][y2 + 1] && !st.count({x1, y1 + 1, x1, y2 + 1})) {
        que.push(Node(x1, y1 + 1, x1, y2 + 1, step + 1));
        st.insert({x1, y1 + 1, x1, y2 + 1});
      }
      if ((x1 < n - 1) && !grid[x1 + 1][y1] && !grid[x1 + 1][y2] && !st.count({x1 + 1, y1, x1 + 1, y2})) {
        que.push(Node(x1 + 1, y1, x1 + 1, y2, step + 1));
        st.insert({x1 + 1, y1, x1 + 1, y2});
      }
      if ((x1 < n - 1) && !grid[x1 + 1][y1] && !grid[x1 + 1][y2] && !st.count({x1, y1, x1 + 1, y1})) {
        que.push(Node(x1, y1, x1 + 1, y1, step + 1));
        st.insert({x1, y1, x1 + 1, y1});
      }
    } else {
      if ((y1 < n - 1) && !grid[x1][y1 + 1] && !grid[x2][y1 + 1] && !st.count({x1, y1 + 1, x2, y1 + 1})) {
        que.push(Node(x1, y1 + 1, x2, y1 + 1, step + 1));
        st.insert({x1, y1 + 1, x2, y1 + 1});
      }
      if ((y1 < n - 1) && !grid[x1][y1 + 1] && !grid[x2][y1 + 1] && !st.count({x1, y1, x1, y1 + 1})) {
        que.push(Node(x1, y1, x1, y1 + 1, step + 1));
        st.insert({x1, y1, x1, y1 + 1});
      }
      if ((x2 < n - 1) && !grid[x2 + 1][y1] && !st.count({x1 + 1, y1, x2 + 1, y1})) {
        que.push(Node(x1 + 1, y1, x2 + 1, y1, step + 1));
        st.insert({x1 + 1, y1, x2 + 1, y1});
      }
    }
  }
  return -1;
}

int main() {
  return 0;
}
