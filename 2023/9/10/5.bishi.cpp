/*************************************************************************
	> File Name: 5.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月10日 星期日 20时49分20秒
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
#include <numeric>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  auto cmp = [&](int a, int b) {
    int cnt_1 = __builtin_popcount(a);
    int cnt_2 = __builtin_popcount(b);
    long x1 = 1L * a * cnt_2;
    long x2 = 1L * b * cnt_1;
    return x1 == x2 ? cnt_1 > cnt_2 : x1 < x2;
  };
  priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
  long sum = accumulate(nums.begin(), nums.end(), 0L);
  for (int x : nums)
    que.push(x);
  while (k) {
    int x = que.top();
    que.pop();
    int cnt = __builtin_popcount(x);
    if (cnt <= k) {
      sum -= x;
      k -= cnt;
    } else {
      while (__builtin_popcount(x) > k) {
        x -= 1 << (31 - __builtin_clz(x));
      }
      if (x)
        que.push(x);
    }
  }
  cout << sum << endl;
  return 0;
}
