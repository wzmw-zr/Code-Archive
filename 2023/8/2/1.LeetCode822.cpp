/*************************************************************************
	> File Name: 1.LeetCode822.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月02日 星期三 09时38分41秒
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
#include <cstdint>
using namespace std;

int flipgame(vector<int>& fronts, vector<int>& backs) {
  int n = fronts.size();
  unordered_set<int> invalid;
  for (int i = 0; i < n; i++) {
    if (fronts[i] == backs[i])
      invalid.insert(fronts[i]);
  }
  int ans = INT32_MAX;
  for (int i = 0; i < n; i++) {
    if (!invalid.count(fronts[i]))
      ans = min(ans, fronts[i]);
    if (!invalid.count(backs[i]))
      ans = min(ans, backs[i]);
  }
  return ans == INT32_MAX ? 0 : ans;
}

int main() {
  return 0;
}
