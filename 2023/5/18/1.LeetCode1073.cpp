/*************************************************************************
	> File Name: 1.LeetCode1073.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月18日 星期四 09时42分52秒
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

vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
  int n = max(arr1.size(), arr2.size());
  reverse(arr1.begin(), arr1.end());
  reverse(arr2.begin(), arr2.end());
  while (arr1.size() < n)
    arr1.push_back(0);
  while (arr2.size() < n)
    arr2.push_back(0);
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) 
    ans[i] = arr1[i] + arr2[i];
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] >= 2) {
      if (i + 1 == ans.size())
        ans.push_back(0);
      ans[i + 1] -= ans[i] / 2;
      ans[i] %= 2;
    } 
    if (ans[i] < 0) {
      if (i + 1 == ans.size())
        ans.push_back(0);
      ans[i + 1] -= ans[i] / 2;
      ans[i] -= (ans[i] / 2) * 2;
      if (ans[i] == -1)
        ans[i + 1] += 1, ans[i] = 1;
    }
  }
  while (ans.size() > 1 && *ans.rbegin() == 0)
    ans.pop_back();
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  return 0;
}
