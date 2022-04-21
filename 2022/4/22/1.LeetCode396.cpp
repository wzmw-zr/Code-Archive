/*************************************************************************
	> File Name: 1.LeetCode396.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月22日 星期五 00时03分19秒
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

int maxRotateFunction(vector<int>& nums) {
  int n = nums.size();
  long sum = 0, val = 0;
  for (int i = 0; i < n; i++) val += i * nums[i], sum += nums[i];
  int ans = val;
  for (int i = 1; i < n; i++) {
    val += sum - 1L * n * nums[n - i];
    ans = max(ans, (int) val);
  }
  return ans;
}

int main() {
  return 0;
}
