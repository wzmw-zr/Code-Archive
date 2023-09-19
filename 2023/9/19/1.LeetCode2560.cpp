/*************************************************************************
	> File Name: 1.LeetCode2560.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月19日 星期二 20时33分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdint>
using namespace std;

int check(vector<int> &nums, int mid) {
  int ans = 0, flag = 0;
  for (int x : nums) {
    if (x <= mid && flag == 0) {
      ans++, flag = 1;
    } else {
      flag = 0;
    }
  }
  return ans;
}

int minCapability(vector<int>& nums, int k) {
  int l = 1, r = 0x3f3f3f3f;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(nums, mid) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
