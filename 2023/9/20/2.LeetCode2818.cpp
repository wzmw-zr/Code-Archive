/*************************************************************************
	> File Name: 2.LeetCode2818.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月20日 星期三 14时44分18秒
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

long long MOD = 1e9 + 7;

long long qpow(long b, long p) {
  long long ans = 1;
  long long base = b;
  while (p) {
    if (p & 1)
      ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    p >>= 1;
  }
  return ans;
}

int maximumScore(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> cnts(1e5 + 10, 0);
  for (int i = 2; i <= 1e5; i++) {
    if (cnts[i])
      continue;
    for (int j = 1; i * j <= 1e5; j++)
      cnts[i * j]++;
  }

  vector<int> vals(n);
  for (int i = 0; i < n; i++)
    vals[i] = cnts[nums[i]];

  vector<int> left(n + 1, -1), right(n + 1, n);
  stack<int> st1, st2;

  for (int i = 0; i < n; i++) {
    while (!st1.empty() && vals[i] > vals[st1.top()])
      st1.pop();
    if (!st1.empty())
      left[i] = st1.top();
    st1.push(i);
  }

  for (int i = n - 1; i >= 0; i--) {
    while (!st2.empty() && vals[i] >= vals[st2.top()])
      st2.pop();
    if (!st2.empty())
      right[i] = st2.top();
    st2.push(i);
  }

  vector<int> inds(n);
  iota(inds.begin(), inds.end(), 0);
  sort(inds.begin(), inds.end(), [&](int x, int y){
    return nums[x] > nums[y];
  });

  long long ans = 1;
  for (long i = 0; i < n && k; i++) {
    int ind = inds[i];
    long l = ind - left[ind], r = right[ind] - ind;
    long p = min(1L * k, l * r);
    ans = ans * qpow(nums[ind], p) % MOD;
    k -= p;
  }
  return ans;
}

int main() {
  return 0;
}
