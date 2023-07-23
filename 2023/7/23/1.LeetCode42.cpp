/*************************************************************************
	> File Name: 1.LeetCode42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 09时49分32秒
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

int trap(vector<int>& height) {
  int n = height.size();
  vector<int> pre = height, suf = height;
  for (int i = 1; i < n; i++)
    pre[i] = max(pre[i], pre[i - 1]);
  for (int i = n - 2; i >= 0; i--)
    suf[i] = max(suf[i], suf[i + 1]);
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += min(pre[i], suf[i]) - height[i];
  return ans;
}

int main() {
  return 0;
}
