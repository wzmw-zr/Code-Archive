/*************************************************************************
	> File Name: 3.LeetCode6067.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月14日 星期六 22时36分07秒
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

int waysToSplitArray(vector<int>& nums) {
  int n = nums.size();
  vector<long> pre(n + 1, 0);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (pre[i + 1] >= pre[n] - pre[i + 1]) cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
