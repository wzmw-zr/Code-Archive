/*************************************************************************
	> File Name: 4.LeetCode6359.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月09日 星期日 14时35分21秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimizeMax(vector<int>& nums, int p) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int l = 0, r = 0x3f3f3f3f;

  function<bool(int)> check = [&](int mmax) -> bool {
    int ind = 0;
    int total = 0;
    while (ind + 1 < n) {
      int cnt = 1;
      while ((ind + 1 < n) && (nums[ind + 1] - nums[ind] <= mmax))
        cnt++, ind++;
      if (ind + 1 < n)
        ind++;
      total += cnt / 2;
    }
    return total >= p;
  };

  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
