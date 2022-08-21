/*************************************************************************
	> File Name: 5.LeetCode6159.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月20日 星期六 22时54分12秒
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
  vector<long long> vals;
  vector<int> fa;
  vector<int> occupy;

  UnionSet() = default;
  UnionSet(int n) 
  : n(n), 
  vals(vector<long long>(n, 0)),
  fa(vector<int>(n)),
  occupy(vector<int>(n, 0)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void set(int ind, int val) {
    vals[ind] = val;
    occupy[ind] = 1;
  }

  void merge(int a, int b) {
    int x = get(a);
    int y = get(b);
    if (x == y)
      return ;
    vals[y] += vals[x];
    fa[x] = y;
  }

  long long query(int x) {
    return vals[get(x)];
  }
};

vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
  int n = nums.size();
  UnionSet u(n);
  vector<long long> ans(n, 0);
  long long mmax = INT64_MIN;
  for (int i = n - 1; i >= 1; i--) {
    int ind = removeQueries[i];
    u.set(ind, nums[ind]);
    if (ind > 0) {
      if (u.occupy[ind - 1])
        u.merge(ind - 1, ind);
    }
    if (ind < n - 1) {
      if (u.occupy[ind + 1])
        u.merge(ind, ind + 1);
    }
    mmax = max(mmax, u.query(ind));
    ans[i - 1] = mmax;
  }
  return ans;
}

int main() {
  return 0;
}
