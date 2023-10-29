/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月29日 星期日 14时34分03秒
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


int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    if (!mp.count(nums[i]))
      mp[nums[i]] = vector<int>(0);
    mp[nums[i]].push_back(i);
  }

  long ans = 0;

  for (auto && [x, inds] : mp) {
    if (x > n)
      continue;
    int left = max(0, inds[0] - x + 1);
    int right = inds[0];
    for (int ind : inds) {
      int l = max(0, ind - x + 1);
      if (l <= right) {
        right = ind;
      } else {
        ans += right - left + 1;
        left = l;
        right = ind;
      }
    }
    ans += right - left + 1;
  }
  cout << ans << endl;
  return 0;
}
