/*************************************************************************
	> File Name: 1.LeetCode1039.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 09时26分22秒
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

// TLE
int minScoreTriangulation(vector<int>& values) {
  map<vector<int>, int> mp;
  function<int(vector<int> &)> dfs = [&](vector<int> &vals) -> int {
    if (vals.size() == 3)
      return vals[0] * vals[1] * vals[2];
    if (mp.count(vals))
      return mp[vals];
    int ans = INT32_MAX;
    int n = vals.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          int t = vals[i] * vals[j] * vals[k];
          if (j > i + 1) {
            vector<int> temp(vals.begin() + i, vals.begin() + j + 1);
            t += dfs(temp);
          }
          if (k > j + 1) {
            vector<int> temp(vals.begin() + j, vals.begin() + k + 1);
            t += dfs(temp);
          }
          if (n - k + i + 1 >= 3) {
            vector<int> temp(vals.begin(), vals.begin() + i + 1);
            for (int p = k; p < n; p++)
              temp.push_back(vals[p]);
            t += dfs(temp);
          }
          ans = min(ans, t);
        }
      }
    }
    return mp[vals] = ans;
  };
  return dfs(values);
}

int main() {
  return 0;
}
