/*************************************************************************
	> File Name: 2.LeetCode6316.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月12日 星期日 10时34分30秒
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

int maxScore(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end(), greater<int>());
  vector<long> pre(n + 1, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + nums[i];
    ans += pre[i + 1] > 0 ? 1 : 0;
  }
  return ans;
}

int main() {
  return 0;
}
