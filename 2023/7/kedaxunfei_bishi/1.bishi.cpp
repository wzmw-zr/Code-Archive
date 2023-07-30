/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月29日 星期六 19时28分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int k = 0;
  while (nums[k] != -1)
    k++;
  int l_min = INT32_MAX, r_min = INT32_MAX;
  for (int i = 0; i < k; i++)
    l_min = min(l_min, nums[i]);
  for (int i = k + 1; i < n; i++)
    r_min = min(r_min, nums[i]);
  cout << l_min + r_min << endl;
  return 0;
}
