/*************************************************************************
	> File Name: 1.LeetCode870.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月08日 星期六 09时13分25秒
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

using PII = pair<int, int>;

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  vector<int> ans(n);
  sort(nums1.begin(), nums1.end());
  vector<PII> nums3;
  for (int i = 0; i < n; i++)
    nums3.push_back(PII(nums2[i], i));
  sort(nums3.begin(), nums3.end());
  int ind_1 = 0, ind_3 = 0;
  vector<int> rest;
  while (ind_1 < n && ind_3 < n) {
    while (ind_1 < n && nums1[ind_1] <= nums3[ind_3].first) {
      rest.push_back(ind_1);
      ind_1++;
    }
    if (ind_1 < n) {
      ans[nums3[ind_3].second] = nums1[ind_1];
      ind_1++;
      ind_3++;
    }
  }
  for (int i = 0; i < rest.size(); i++) 
    ans[nums3[ind_3 + i].second] = nums1[rest[i]];
  return ans;
}

int main() {
  return 0;
}
