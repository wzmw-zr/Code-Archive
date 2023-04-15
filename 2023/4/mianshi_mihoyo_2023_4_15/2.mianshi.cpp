/*************************************************************************
	> File Name: 2.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月15日 星期六 20时54分22秒
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

// a0 a2 a4 ... 
// a1 a3 a5
//
// bi - b_{i - 1} = a_{i + 1} - a_{i - 1}
//
// l1 <= l2
// [] []
int same_area(int l1, int r1, int l2, int r2) {
  if (r1 < l2)
    return 0;
  if (r1 >= l2 && r1 <= r2)
    return r1 - l2 + 1;
  return r2 - l2 + 1;
}

int numMethods(vector<int> &nums) {
  int n = nums.size();
  vector<int> even;
  vector<int> odd;
  int pre = 0;
  // start from a0
  int low_1 = 1, up_1 = nums[0] - 1;
  for (int i = 1; i < n; i += 2) {
    even.push_back(pre + nums[i] - nums[i - 1]);
    pre += nums[i] - nums[i - 1];
    int low = 1;
    int up = nums[i] - 1;
    if (i + 1 < n)
      up = min(up, nums[i + 1] - 1);
    low_1 = max(low_1, low - pre);
    up_1 = min(up_1, up - pre);
  }

  pre = 0;
  // start from a1
  int low_2 = 1, up_2 = nums[0] - 1;
  if (n > 2)
    up_2 = min(up_2, nums[1] - 1);
  for (int i = 2; i < n; i += 2) {
    odd.push_back(pre + nums[i] - nums[i - 1]);
    pre += nums[i] - nums[i - 1];
    int low = 1;
    int up = nums[i] - 1;
    if (i + 1 < n)
      up = min(up, nums[i + 1] - 1);
    low_2 = max(low_2, low - pre);
    up_2 = min(up_2, up - pre);
  }

  int low_3 = nums[0] - up_2, up_3 = nums[0] - low_2;
  if (low_1 < low_3)
    return same_area(low_1, up_1, low_3, up_3);
  return same_area(low_3, up_3, low_1, up_1);
}

int main() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> b[i];
  cout << numMethods(b) << endl;
  return 0;
}
