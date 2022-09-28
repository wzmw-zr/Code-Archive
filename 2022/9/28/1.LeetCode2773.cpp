/*************************************************************************
	> File Name: 1.LeetCode2773.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月28日 星期三 09时59分54秒
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

struct BigInt {
  vector<int> digits;

  BigInt() = default;

  BigInt(int x) {
    do {
      digits.push_back(x % 10);
      x /= 10;
    } while (x);
  }

  BigInt(vector<int> &nums) : digits(move(nums)) {};

  bool operator<(const struct BigInt &that) const {
    if (this->digits.size() == that.digits.size()) {
      int n = this->digits.size();
      for (int i = n - 1; i >= 0; i--) {
        if (this->digits[i] == that.digits[i])
          continue;
        return this->digits[i] > that.digits[i];
      }
      return false;
    }
    return this->digits.size() > that.digits.size();
  };

  bool operator==(const struct BigInt &that) const {
    return this->digits == that.digits;
  }

  BigInt operator*(int x) {
    vector<int> nums = digits;
    int n = nums.size();
    for (int i = 0; i < n; i++) 
      nums[i] *= x;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 10) {
        if (i + 1 == nums.size()) 
          nums.push_back(0);
        nums[i + 1] += nums[i] / 10;
        nums[i] %= 10;
      }
    }
    return nums;
  }

  int to_int() {
    int ans = 0;
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--) 
      ans = (ans * 10) + digits[i];
    return ans;
  }
};

int getKthMagicNumber(int k) {
  vector<int> multiply = {3, 5, 7};
  priority_queue<BigInt> que;
  set<BigInt> st;
  que.push(BigInt(1));
  st.insert(BigInt(1));
  int ans = 1;
  while (!que.empty()) {
    BigInt t = que.top();
    que.pop();
    if (!(--k)) {
      ans = t.to_int();
      break;
    }
    for (int x : multiply) {
      if (!st.count(t * x)) {
        st.insert(t * x);
        que.push(t * x);
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
