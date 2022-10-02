/*************************************************************************
	> File Name: 1.LeetCode6198.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 09时19分38秒
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

const int BASE = 3e4 + 10;

struct BIT {
  vector<int> vals;
  BIT() : vals(vector<int>(2 * BASE + 10, 0)) {}

  int lowbit(int x) {
    return x & -x;
  }

  int query(int x) {
    x += BASE;
    int ans = 0;
    while (x) {
      ans += vals[x];
      x -= lowbit(x);
    }
    return ans;
  }

  void update(int x, int val) {
    x += BASE;
    while (x < vals.size()) {
      vals[x] += val;
      x += lowbit(x);
    }
  }
};

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
  BIT bit;
  int n = nums1.size();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int val = nums1[i] - nums2[i] + diff;
    ans += bit.query(val);
    bit.update(nums1[i] - nums2[i], 1);
  }
  return ans;
}

int main() {
  return 0;
}
