/*************************************************************************
	> File Name: 2.LeetCode6390.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月23日 星期日 10时35分15秒
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

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
  int n = nums.size();
  map<int, int> mp;
  for (int i = 0; i < k - 1; i++)
    mp[nums[i]]++;
  vector<int> ans;
  for (int i = k - 1; i < n; i++) {
    mp[nums[i]]++;
    int cnts = 0;
    for (auto && [val, cnt] : mp) {
      cnts += cnt;
      if (cnts >= x) {
        ans.push_back(min(val, 0));
        break;
      }
    }
    if (!(--mp[nums[i - k + 1]]))
      mp.erase(nums[i - k + 1]);
  }
  return ans;
}

int main() {
  return 0;
}
