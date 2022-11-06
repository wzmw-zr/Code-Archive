/*************************************************************************
	> File Name: 2.LeetCode6229.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月06日 星期日 10时31分27秒
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

vector<int> applyOperations(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      nums[i] *= 2;
      nums[i + 1] = 0;
    }
  }
  vector<int> ans(n);
  int left = 0, right = n - 1;
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      ans[right--] = 0;
    } else {
      ans[left++] = nums[i];
    }
  }
  return ans;
}

int main() {
  return 0;
}
