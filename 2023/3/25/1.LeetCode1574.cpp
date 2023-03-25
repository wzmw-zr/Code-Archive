/*************************************************************************
	> File Name: 1.LeetCode1574.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月25日 星期六 09时47分50秒
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

int findLengthOfShortestSubarray(vector<int>& arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l < n - 1 && arr[l] <= arr[l + 1])
    l++;
  if (l == n - 1)
    return 0;
  while (r > 0 && arr[r - 1] <= arr[r])
    r--;
  int ans = max(l + 1, n - r);
  for (int i = l; i >= 0; i--) {
    int x = r, y = n;
    while (x < y) {
      int mid = (x + y) / 2;
      if (arr[mid] >= arr[i])
        y = mid;
      else
        x = mid + 1;
    }
    ans = max(ans, i + 1 + n - x);
  }

  for (int i = r; i < n; i++) {
    int x = -1, y = l;
    while (x < y) {
      int mid = (x + y + 1) / 2;
      if (arr[mid] <= arr[i])
        x = mid;
      else
        y = mid - 1;
    }
    ans = max(ans, x + 1 + n - i);
  }

  return n - ans;
}

int main() {
  return 0;
}
