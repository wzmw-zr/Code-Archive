/*************************************************************************
	> File Name: 3.LeetCode2196.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月12日 星期六 19时57分01秒
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
  unordered_map<int, TreeNode *> mp;
  unordered_map<int, int> in_degree;
  for (auto x : descriptions) {
    if (!mp.count(x[0])) mp[x[0]] = new TreeNode(x[0]);
    if (!mp.count(x[1])) mp[x[1]] = new TreeNode(x[1]);
    if (!in_degree.count(x[0])) in_degree[x[0]] = 0;
    if (!in_degree.count(x[1])) in_degree[x[1]] = 0;
    in_degree[x[1]]++;
    if (x[2]) mp[x[0]]->left = mp[x[1]];
    else mp[x[0]]->right = mp[x[1]];
  }
  for (auto &&[x, deg] : in_degree) {
    if (deg) continue;
    return mp[x];
  }
  return nullptr;
}

int main() {
  return 0;
}
