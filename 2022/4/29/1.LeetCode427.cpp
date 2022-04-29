/*************************************************************************
	> File Name: 1.LeetCode427.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月29日 星期五 08时51分41秒
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

class Node {
public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};


Node* construct(vector<vector<int>>& grid) {
  int n = grid.size();
  if (n == 1) 
    return new Node(grid[0][0], true);
  int zero = 0, one = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) zero++;
      else one++;
    }
  }
  if (!zero || !one) 
    return new Node(grid[0][0], true);
  Node *node = new Node(0, false);
  vector<vector<int>> top_left(n / 2, vector<int>(n / 2));
  vector<vector<int>> top_right(n / 2, vector<int>(n / 2));
  vector<vector<int>> bottom_left(n / 2, vector<int>(n / 2));
  vector<vector<int>> bottom_right(n / 2, vector<int>(n / 2));
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      top_left[i][j] = grid[i][j];
      top_right[i][j] = grid[i][j + n / 2];
      bottom_left[i][j] = grid[i + n / 2][j];
      bottom_right[i][j] = grid[i + n / 2][j + n / 2];
    }
  }
  node->topLeft = construct(top_left);
  node->topRight = construct(top_right);
  node->bottomLeft = construct(bottom_left);
  node->bottomRight = construct(bottom_right);
  return node;
}

int main() {
  return 0;
}
