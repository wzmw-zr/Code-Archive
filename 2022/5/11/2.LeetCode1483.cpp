/*************************************************************************
	> File Name: 2.LeetCode1483.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月11日 星期三 14时52分31秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

class TreeAncestor {
public:
  vector<vector<int>> dp;

  TreeAncestor(int n, vector<int>& parent) : dp(vector<vector<int>>(n, vector<int>(20, -1))) {
    for (int i = 0; i < n; i++) dp[i][0] = parent[i];
    for (int i = 1; i < 20; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[j][i - 1] == -1) dp[j][i] = -1;
        else dp[j][i] = dp[dp[j][i - 1]][i - 1];
      }
    }
  }

  int lowbit(int x) { return x & -x; }

  int getKthAncestor(int node, int k) {
    if (node >= dp.size()) return -1;
    while (node != -1 && k) {
      int val = lowbit(k);
      int level = log2(val);
      node = dp[node][level];
      k -= val;
    }
    return node;
  }
};

int main() {
  return 0;
}
