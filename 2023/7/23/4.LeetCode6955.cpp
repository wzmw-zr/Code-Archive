/*************************************************************************
	> File Name: 4.LeetCode6955.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 10时41分45秒
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

// WA
int maxIncreasingGroups(vector<int>& usageLimits) {
  int n = usageLimits.size();
  sort(usageLimits.begin(), usageLimits.end());
  int l = 1, r = n;
  function<bool(int)> check = [&](int x) {
    for (int i = n - 1, j = x; i >= 0 && j > 0; i--, j--) {
      if (usageLimits[i] < j)
        return false;
    }
    return true;
  };
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
