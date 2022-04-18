/*************************************************************************
	> File Name: 4.LeetCode6073.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月18日 星期一 11时09分51秒
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
  int ind;
  char ch;
  vector<Node *> children;

  Node() = default;
  Node(int ind, char ch) : ind(ind), ch(ch), children(vector<Node *>(0)) {}
};

int dfs(Node *root, int &ans) {
  if (!root) return 0;
  vector<int> heights(2, 0);
  for (auto child : root->children) {
    int h = dfs(child, ans);
    if (child->ch != root->ch) {
      if (h > heights[1]) {
        heights[0] = heights[1];
        heights[1] = h;
      } else {
        if (h > heights[0]) heights[0] = h;
      }
    }
  }
  ans = max(ans, heights[0] + heights[1] + 1);
  return heights[1] + 1;
}

int longestPath(vector<int>& parent, string s) {
  int n = parent.size();
  vector<Node *> nodes(n, nullptr);
  for (int i = 0; i < n; i++) nodes[i] = new Node(i, s[i]);
  for (int i = 1; i < n; i++) nodes[parent[i]]->children.push_back(nodes[i]);
  int ans = 0;
  dfs(nodes[0], ans);
  return ans;
}

int main() {
  return 0;
}
