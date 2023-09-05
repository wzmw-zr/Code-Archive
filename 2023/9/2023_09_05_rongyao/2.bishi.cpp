/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月05日 星期二 19时26分37秒
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
  int x;
  vector<int> nums;
  while (cin >> x)
    nums.push_back(x);
  nums.pop_back();
  unordered_map<int, int> mp;
  int n = nums.size();
  for (int i = 0; i < n; i++)
    mp[nums[i]] = i;
  int flag = 0, p = 0, q = 0;
  for (int i = 0; i < n; i++) {
    if (mp.count(x - nums[i]) && x != 2 * nums[i]) {
      flag = 1;
      p = nums[i];
      q = x - nums[i];
      break;
    }
  }
  cout << flag << " " << p << " " << q << endl;
  return 0;
}
