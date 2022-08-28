/*************************************************************************
	> File Name: 2.LeetCode6160.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月28日 星期日 10时31分28秒
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

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<int> pre(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + nums[i];
  vector<int> ans;
  auto bs_last_le = [&](int x) {
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (pre[mid] <= x)
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  };
  for (int x : queries)
    ans.push_back(bs_last_le(x));
  return ans;
}

int main() {
  return 0;
}
