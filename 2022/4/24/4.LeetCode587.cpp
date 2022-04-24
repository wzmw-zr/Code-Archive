/*************************************************************************
	> File Name: 4.LeetCode587.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月24日 星期日 21时21分35秒
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

int cross(vector<int> &p, vector<int> &q, vector<int> &r) {
  return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
}

vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
  if (trees.size() < 4) return trees;
  int n = trees.size();
  sort(trees.begin(), trees.end());
  vector<int> check(n, 0);
  vector<int> que({0, 1});
  for (int i = 2; i < n; i++) {
    while (que.size() > 1) {
      int m = que.size();
      if (cross(trees[que[m - 2]], trees[que[m - 1]], trees[i]) < 0) {
        que.pop_back();
      } else break;
    }
    que.push_back(i);
  }
  for (int x : que) check[x] = 1;
  check[0] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (check[i]) continue;
    while (que.size() > 1) {
      int m = que.size();
      if (cross(trees[que[m - 2]], trees[que[m - 1]], trees[i]) < 0) {
        que.pop_back();
      } else break;
    }
    que.push_back(i);
  }
  que.pop_back();
  vector<vector<int>> ans;
  for (int ind : que) ans.push_back(trees[ind]);
  return ans;
}

int main() {
  return 0;
}
