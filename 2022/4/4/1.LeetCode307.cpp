/*************************************************************************
	> File Name: 1.LeetCode307.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月04日 星期一 00时38分55秒
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
  vector<int> sum;

  BIT() = default;
  BIT(int len) : nums(vector<int>(len + 10, 0)), sum(vector<int>(len + 10, 0)), n(len) {}

  int lowbit(int x) { return x & -x; }

  void add(int ind, int val) {
    nums[ind] += val;
    while (ind <= n) {
      sum[ind] += val;
      ind += lowbit(ind);
    }
  }

  int query(int ind) {
    int ans = 0;
    while (ind) {
      ans += sum[ind];
      ind -= lowbit(ind);
    }
    return ans;
  }
};

class NumArray {
public:
  BIT bit;

  NumArray(vector<int>& nums) : bit(BIT(nums.size() + 10)) {
    for (int i = 0; i < nums.size(); i++) bit.add(i + 1, nums[i]);
  }

  void update(int index, int val) {
    bit.add(index + 1, val - bit.nums[index + 1]);
  }

  int sumRange(int left, int right) {
    return bit.query(right + 1) - bit.query(left);
  }
};

int main() {
  return 0;
}
