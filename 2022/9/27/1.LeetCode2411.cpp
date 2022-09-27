/*************************************************************************
	> File Name: 1.LeetCode2411.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月27日 星期二 09时37分31秒
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

// TLE
int binary_search_first(vector<int> &nums, int left) {
  int l = 0, r = static_cast<int>(nums.size()) - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] >= left)
      r = mid;
    else
      l = mid + 1;
  }
  return nums[l];
}

vector<int> smallestSubarrays(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> bits(32, vector<int>(0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 31; j++) {
      if (nums[i] & (1 << j))
        bits[j].push_back(i);
    }
  }
  vector<int> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
    suf[i] = suf[i + 1] | nums[i];
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int pos = i;
    for (int j = 0; j <= 31; j++) {
      if (!(suf[i] & (1 << j)))
        continue;
      int ind = binary_search_first(bits[j], i);
      pos = max(pos, ind);
    }
    ans[i] = pos - i + 1;
  }
  return ans;
}

int main() {
  return 0;
}
