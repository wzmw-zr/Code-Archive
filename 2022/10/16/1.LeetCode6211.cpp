/*************************************************************************
	> File Name: 1.LeetCode6211.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 09时29分09秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
  int n = nums.size();
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto && e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  vector<int> vals = nums;
  function<void(int, int)> dfs1 = [&](int ind, int fa) {
    for (int next_ind : graph[ind]) {
      if (next_ind == fa)
        continue;
      dfs1(next_ind, ind);
      vals[ind] += vals[next_ind];
    }
  };
  dfs1(0, -1);


  vector<int> block_vals(n, 0);
  function<bool(int, int, int)> dfs2 = [&](int ind, int fa, int val) -> bool {
    int sum = nums[ind];
    for (int next_ind : graph[ind]) {
      if (next_ind == fa)
        continue;
      if (!dfs2(next_ind, ind, val)) 
        return false;
      if (block_vals[next_ind] == val)
        continue;
      sum += block_vals[next_ind];
    }
    if (sum > val)
      return false;
    block_vals[ind] = sum;
    return true;
  };

  for (int i = 1; i <= vals[0]; i++) {
    if (vals[0] % i == 0 && dfs2(0, -1, i))
      return vals[0] / i - 1;
  }
  return -1;
}

int main() {
  return 0;
}
