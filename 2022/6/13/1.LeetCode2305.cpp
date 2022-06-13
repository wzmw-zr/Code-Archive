/*************************************************************************
	> File Name: 1.LeetCode2305.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月13日 星期一 20时45分41秒
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

int distributeCookies(vector<int>& cookies, int k) {
  int n = cookies.size();
  int ans = INT32_MAX;
  vector<int> cnts(k, 0);
  
  function<void(int)> dfs = [&](int ind) {
    if (ind == n) {
      int mmax = INT32_MIN;
      for (int i = 0; i < k; i++) mmax = max(mmax, cnts[i]);
      ans = min(ans, mmax);
      return ;
    }
    for (int i = 0; i < k; i++) {
      cnts[i] += cookies[ind];
      dfs(ind + 1);
      cnts[i] -= cookies[ind];
    }
  };

  dfs(0);
  return ans;
}

int main() {
  return 0;
}
