/*************************************************************************
	> File Name: 4.LeetCode6263.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月10日 星期六 22时52分44秒
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

int maxJump(vector<int>& stones) {
  int n = stones.size();
  int ans = 0;
  int ind;
  for (ind = 1; ind < n; ind += 2) {
    int pre = max(0, ind - 2);
    ans = max(ans, stones[ind] - stones[pre]);
  }
  if (ind == n)
    ans = max(ans, stones[n - 1] - stones[n - 2]);
  for (ind = 2; ind < n; ind += 2) {
    int pre = max(0, ind - 2);
    ans = max(ans, stones[ind] - stones[pre]);
  }
  if (ind == n)
    ans = max(ans, stones[n - 1] - stones[n - 2]);
  return ans;
}

int main() {
  return 0;
}
