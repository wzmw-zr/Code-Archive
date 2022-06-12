/*************************************************************************
	> File Name: 4.LeetCode6098.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月12日 星期日 11时21分41秒
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

long long countSubarrays(vector<int>& nums, long long k) {
  int n = nums.size();
  vector<long long> pre(n + 1, 0);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

  auto find_last_le = [&](int ind) -> int {
    int n = pre.size();
    int l = ind, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if ((pre[mid] - pre[ind]) * (mid - ind) <= k) l = mid;
      else r = mid - 1;
    }
    return l;
  };

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int ind = find_last_le(i);
    ans += 1L * (ind - i);
  }
  return ans;
}

int main() {
  return 0;
}
