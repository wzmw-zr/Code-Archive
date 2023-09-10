/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月10日 星期日 20时32分09秒
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
  int l = 0, r = n - 1; 
  long ans = 0;
  int val = 0;
  while (l < r) {
    ans += nums[r--] - val;
    val = nums[l++];
  }
  if (l == r) {
    ans += nums[r] - val;
  }
  cout << ans << endl;
  return 0;
}
