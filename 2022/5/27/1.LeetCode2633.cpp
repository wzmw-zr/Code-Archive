/*************************************************************************
	> File Name: 1.LeetCode2633.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月27日 星期五 08时45分12秒
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

int bs_last_lt(vector<int> &nums, int x) {
  int l = 0, r = static_cast<int>(nums.size()) - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (nums[mid] < x) l = mid;
    else r = mid - 1;
  }
  return nums[l];
}

int bs_first_gt(vector<int> &nums, int x) {
  int l = 0, r = static_cast<int>(nums.size()) - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] > x) r = mid;
    else l = mid + 1;
  }
  return nums[l];
}

int findClosest(vector<string>& words, string word1, string word2) {
  vector<int> inds1, inds2;
  for (int i = 0; i < words.size(); i++) {
    if (words[i] == word1) inds1.push_back(i);
    if (words[i] == word2) inds2.push_back(i);
  }
  if (inds1.size() == 0 || inds2.size() == 0) return words.size();
  int ans = INT32_MAX;
  for (int ind : inds1) {
    int x1 = bs_last_lt(inds2, ind);
    int x2 = bs_first_gt(inds2, ind);
    ans = min({ans, abs(x1 - ind), abs(x2 - ind)});
  }
  return ans;
}

int main() {
  return 0;
}
