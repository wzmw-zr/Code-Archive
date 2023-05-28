/*************************************************************************
	> File Name: 3.LeetCode6464.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月27日 星期六 23时00分05秒
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

static const int MAX_N = 1e5;

struct UnionSet {
  vector<int> fa;
  vector<int> size;

  UnionSet() = default;
  UnionSet(vector<int> &nums) : fa(vector<int>(MAX_N + 10)), size(vector<int>(MAX_N + 10, 0)) {
    iota(fa.begin(), fa.end(), 0);
    for (int x : nums)
      size[x]++;
  }

  int find(int x) {
    return fa[x] = (x == fa[x] ? x : find(fa[x]));
  }

  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b)
      return;
    if (size[a] > size[b]) {
      fa[b] = a;
      size[a] += size[b];
    } else {
      fa[a] = b;
      size[b] += size[a];
    }
  }
};

bool canTraverseAllPairs(vector<int>& nums) {
  unordered_set<int> st(nums.begin(), nums.end());
  if (st.count(1))
    return false;
  vector<int> is_prime(MAX_N + 10, 1);
  vector<int> prime_divisor(MAX_N + 10, 0);
  iota(prime_divisor.begin(), prime_divisor.end(), 0);
  for (int i = 2; i <= MAX_N; i++) {
    if (!is_prime[i])
      continue;
    for (int j = 2; i * j <= MAX_N; j++)
      is_prime[i * j] = 0, prime_divisor[i * j] = i;
  }
  UnionSet u(nums);
  for (int x : st) {
    int x_t = x;
    while (x_t != 1) {
      int p = prime_divisor[x_t];
      x_t /= p;
      u.merge(x, p);
    }
  }
  int n = nums.size();
  for (int i = 2; i <= MAX_N; i++) {
    if (u.size[i] == n)
      return true;
  }
  return false;
}

int main() {
  return 0;
}
