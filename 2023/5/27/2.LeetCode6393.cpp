/*************************************************************************
	> File Name: 2.LeetCode6393.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月27日 星期六 22时42分30秒
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

long long maxStrength(vector<int>& nums) {
  vector<int> pos, neg;
  int have_zero = 0;
  for (int x : nums) {
    if (x > 0)
      pos.push_back(x);
    else if (x < 0)
      neg.push_back(x);
    else
      have_zero = 1;
  }
  sort(pos.begin(), pos.end(), greater<int>());
  sort(neg.begin(), neg.end());
  if (pos.size() == 0 && neg.size() <= 1)
    return have_zero ? 0 : neg[0];
  long ans = 1;
  for (int x : pos)
    ans *= x;
  for (int i = 0; i + 1 < neg.size(); i += 2)
    ans *= neg[i] * neg[i + 1];
  return ans;
}

int main() {
  return 0;
}
