/*************************************************************************
	> File Name: 1.LeetCode1375.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月14日 星期三 09时24分54秒
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

int numTimesAllBlue(vector<int>& flips) {
  int n = flips.size();
  int mmax_ind = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    mmax_ind = max(mmax_ind, flips[i]);
    if (mmax_ind == (i + 1))
      ans++;
  }
  return ans;
}

int main() {
  return 0;
}
