/*************************************************************************
	> File Name: 3.LeetCode6392.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月23日 星期日 10时52分09秒
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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int minOperations(vector<int>& nums) {
  int n = nums.size();
  int val = nums[0];
  for (int i = 0; i < n; i++)
    val = gcd(val, nums[i]);
  if (val > 1)
    return -1;
  int ans = INT32_MAX;
  for (int i = 0; i < n; i++) {
    val = nums[i];
    if (val == 1) {
      int cnt = 0;
      for (int x : nums)
        cnt += x == 1 ? 0 : 1;
      return cnt;
    }
    int ind = i;
    while (ind < n) {
      val = gcd(val, nums[ind]);
      if (val == 1) {
        int len = ind - i + 1;
        ans = min(ans, n + len - 2);
        break;
      }
      ind++;
    }
  }
  return ans;
}

int main() {
  return 0;
}
