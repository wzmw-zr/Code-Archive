/*************************************************************************
	> File Name: 2.LeetCode5999.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 01时21分31秒
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

struct BIT {
  int n;
  vector<int> nums;

  BIT() = default;
  BIT(int n) : n(n), nums(vector<int>(n + 1, 0)) {}

  int lowbit(int x) {
    return x & -x;
  }

  void update(int ind) {
    while (ind <= n) {
      nums[ind]++;
      ind += lowbit(ind);
    }
  }

  int query(int ind) {
    int ans = 0;
    while (ind) {
      ans += nums[ind];
      ind -= lowbit(ind);
    }
    return ans;
  }

  int query(int ind_1, int ind_2) {
    return query(ind_2) - query(ind_1 - 1);
  }
};

long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  vector<int> inds(n);
  BIT bit(n);
  for (int i = 0; i < n; i++) 
    inds[nums2[i]] = i;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int ind = inds[nums1[i]];
    bit.update(ind + 1);
    long left = bit.query(1, ind);
    long right = n - ind - 1 - bit.query(ind + 2, n);
    ans += left * right;
  }
  return ans;
}

int main() {
  return 0;
}
