/*************************************************************************
	> File Name: 1.LeetCode2104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月04日 星期五 11时47分37秒
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

long long subArrayRanges(vector<int>& nums) {
  int n = nums.size();
  vector<vector<long>> mmin(n + 1, vector<long>(n + 1, INT64_MAX));
  vector<vector<long>> mmax(n + 1, vector<long>(n + 1, INT64_MIN));
  for (int i = 0; i < n; i++) {
    mmin[i][i] = nums[i];
    mmax[i][i] = nums[i];
  }
  long ans = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j + i <= n; j++) {
      mmin[j][j + i - 1] = min(mmin[j][j + i - 2], static_cast<long>(nums[j + i - 1]));
      mmax[j][j + i - 1] = max(mmax[j][j + i - 2], static_cast<long>(nums[j + i - 1]));
      ans += mmax[j][j + i - 1] - mmin[j][j + i - 1];
    }
  }
  return ans;
}

int main() {
  return 0;
}
