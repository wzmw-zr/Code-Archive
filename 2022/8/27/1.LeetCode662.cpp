/*************************************************************************
	> File Name: 1.LeetCode662.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月27日 星期六 09时00分21秒
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct BigInt {
  vector<int> digits;

  BigInt() = default;
  BigInt(int x) : digits(vector<int>(0)) {
    do {
      digits.push_back(x % 10);
      x /= 10;
    } while (x);
  }
  BigInt(vector<int> &&nums) : digits(move(nums)) {}
  BigInt(const struct BigInt &that) : digits(that.digits) {}

  bool operator<(const struct BigInt &that) {
    int n = this->digits.size(), m = that.digits.size();
    if (n > m)
      return false;
    if (n < m)
      return true;
    for (int i = n - 1; i >= 0; i--) {
      if (this->digits[i] == that.digits[i])
        continue;
      return this->digits[i] < that.digits[i];
    }
    return true;
  }

  struct BigInt operator*(int x) {
    vector<int> nums = digits;
    int n = nums.size();
    for (int i = 0; i < n; i++)
      nums[i] *= x;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 10)
        continue;
      int t = nums[i] / 10;
      nums[i] %= 10;
      if (i + 1 == nums.size())
        nums.push_back(0);
      nums[i + 1] += t;
    }
    return nums;
  }
  
  struct BigInt operator+(int x) {
    vector<int> nums = digits;
    nums[0] += x;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 10)
        continue;
      int t = nums[i] / 10;
      nums[i] %= 10;
      if (i + 1 == nums.size())
        nums.push_back(0);
      nums[i + 1] += t;
    }
    return nums;
  }

  struct BigInt operator-(struct BigInt &that) {
    vector<int> nums1 = this->digits;
    vector<int> nums2 = that.digits;
    int m = nums2.size();
    for (int i = 0; i < m; i++) {
      nums1[i] -= nums2[i];
      if (nums1[i] < 0) {
        nums1[i] += 10;
        nums1[i + 1] -= 1;
      }
    }
    while (*nums1.rbegin() == 0 && nums1.size() > 1)
      nums1.pop_back();
    return nums1;
  }

  long to_num() {
    long ans = 0;
    long base = 1;
    for (long x : digits) {
      ans += x * base;
      base *= 10;
    }
    return ans;
  }
};

ostream & operator<<(ostream &out, BigInt &num) {
  for (int x : num.digits)
    out << x;
  return out;
}

int widthOfBinaryTree(TreeNode* _root) {
  unordered_map<int, BigInt> left, right;
  function<void(TreeNode *, int, BigInt)> dfs = [&](TreeNode *root, int level, BigInt id) -> void {
    if (!root) 
      return ;
    if (!left.count(level))
      left[level] = id;
    else {
      if (id < left[level])
        left[level] = id;
    }
    if (!right.count(level))
      right[level] = id;
    else {
      if (right[level] < id)
        right[level] = id;
    }
    dfs(root->left, level + 1, id * 2);
    dfs(root->right, level + 1, id * 2 + 1);
  };
  dfs(_root, 0, 1);
  long ans = 1;
  for (auto && [level, left_id] : left) 
    ans = max(ans, (right[level] - left_id + 1).to_num());
  return ans;
}

int main() {
  return 0;
}
