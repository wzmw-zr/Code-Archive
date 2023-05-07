/*************************************************************************
	> File Name: 4.LeetCode6419.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月07日 星期日 10时55分12秒
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
#include <cmath>
using namespace std;

int minIncrements(int n, vector<int>& cost) {
  int ans = 0;
  for (int i = (n - 1) / 2; i >= 1; i--) {
    int ind = i - 1;
    int mmax = max(cost[2 * ind + 1], cost[2 * ind + 2]);
    ans += mmax - cost[2 * ind + 1] + mmax - cost[2 * ind + 2];
    cost[ind] += mmax;
  }
  return ans;
}

int main() {
  return 0;
}
