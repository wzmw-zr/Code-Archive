/*************************************************************************
	> File Name: 1.LeetCode565.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月17日 星期日 09时18分41秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct UnionSet {
  int n;
  vector<int> cnt;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int n) : n(n), cnt(vector<int>(n, 1)), fa(vector<int>(n)) {
    for (int i = 0; i < n; i++) fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b) return ;
    fa[a] = b;
    cnt[b] += cnt[a];
  }
};

int arrayNesting(vector<int>& nums) {
  int n = nums.size();
  UnionSet u(n);
  for (int i = 0; i < n; i++) u.merge(i, nums[i]);
  int mmax = 0;
  for (int i = 0; i < n; i++) mmax = max(mmax, u.cnt[i]);
  return mmax;
}

int main() {
  return 0;
}
