/*************************************************************************
	> File Name: 1.LeetCode1775.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月07日 星期三 11时29分49秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int change(vector<int> &cnt1, vector<int> &cnt2, int target) {
  vector<int> ops(7, 0);
  for (int i = 1; i <= 6; i++) {
    ops[i - 1] += cnt1[i];
    ops[6 - i] += cnt2[i];
  }
  int ans = 0;
  for (int i = 5; i >= 1; i--) {
    if (target <= 0)
      break;
    int cnt = min(int(ceil(target * 1.0 / i)), ops[i]);
    ans += cnt;
    target -= i * cnt;
  }
  return ans;
}

int minOperations(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size(), m = nums2.size();
  if (n * 6 < m || m * 6 < n)
    return -1;
  vector<int> cnt1(7, 0), cnt2(7, 0);
  int sum = 0;
  for (int x : nums1) {
    cnt1[x]++;
    sum += x;
  }
  for (int x : nums2) {
    cnt2[x]++;
    sum -= x;
  }
  if (sum == 0)
    return 0;
  if (sum > 0)
    return change(cnt1, cnt2, sum);
  return change(cnt2, cnt1, sum * -1);
}

int main() {
  return 0;
}
