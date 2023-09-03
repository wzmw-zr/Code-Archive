/*************************************************************************
	> File Name: 2.LeetCode6952.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月03日 星期日 10时38分19秒
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


long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
  int n = nums.size();
  vector<int> flags(n, 0);
  vector<int> inds;
  for (int i = 0; i < n; i++) {
    if (nums[i] % modulo == k)
      inds.push_back(i);
  }
  if (inds.size() < k)
    return 0;
  int m = inds.size();
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int right = i + (k ? 0 : 1) * modulo + k - 1; right < m; right += modulo) {
      ans += 1L * (i ? inds[i] - inds[i - 1] : inds[i] + 1) * (right == m - 1 ? n - inds[right] : inds[right + 1] - inds[right]);
    }
  }
  if (k == 0) {
    int ind = 0;
    while (ind < n) {
      while (ind < n && nums[ind] % modulo == k)
        ind++;
      if (ind == n)
        continue;
      int left = ind;
      while (ind < n && nums[ind] % modulo != k)
        ind++;
      int len = ind - left;
      ans += 1L * len * (len + 1) / 2;
    }
  }
  return ans;
}

int main() {
  return 0;
}
