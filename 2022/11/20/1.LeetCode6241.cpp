/*************************************************************************
	> File Name: 1.LeetCode6241.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月20日 星期日 10时30分37秒
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

int unequalTriplets(vector<int>& nums) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
