/*************************************************************************
	> File Name: 4.LeetCode6186.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月17日 星期六 22时51分28秒
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

// TLE
struct SegTree {
  int n;
  vector<int> num;
  vector<int> lazy;

  SegTree() = default;
  SegTree(int n) : n(n), num(vector<int>(n * 4 + 10, 0)), lazy(vector<int>(n * 4 + 10, 0)) {}

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    num[ind * 2 + 1] |= lazy[ind];
    num[ind * 2 + 2] |= lazy[ind];
    lazy[ind * 2 + 1] |= lazy[ind];
    lazy[ind * 2 + 2] |= lazy[ind];
    lazy[ind] = 0;
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    num[ind] = num[ind * 2 + 1] | num[ind * 2 + 2];
  }

  void update(int ind, int l, int r, int s, int t, int val) {
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      num[ind] = val;
      lazy[ind] = val;
      return ;
    }
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    if (s <= mid)
      update(ind * 2 + 1, l, mid, s, t, val);
    if (t > mid)
      update(ind * 2 + 2, mid + 1, r, s, t, val);
    push_up(ind, l, r);
  }

  void update(int s, int t, int val) {
    update(0, 0, n - 1, s, t, val);
  }

  int query(int ind, int l, int r, int s, int t) {
    if (r < s || l > t)
      return 0;
    if (l >= s && r <= t) 
      return num[ind];
    push_down(ind, l, r);
    int ans = 0;
    int mid = (l + r) / 2;
    if (s <= mid)
      ans |= query(ind * 2 + 1, l, mid, s, t);
    if (t > mid)
      ans |= query(ind * 2 + 2, mid + 1, r, s, t);
    push_up(ind, l, r);
    return ans;
  }

  int query(int s, int t) {
    return query(0, 0, n - 1, s, t);
  }
};

vector<int> smallestSubarrays(vector<int>& nums) {
  int n = nums.size();
  SegTree segtree(n);
  for (int i = 0; i < n; i++) 
    segtree.update(i, i, nums[i]);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int val = segtree.query(i, n - 1);
    int l = i, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (segtree.query(i, mid) >= val) 
        r = mid;
      else 
        l = mid + 1;
    }
    ans[i] = l - i + 1;
  }
  return ans;
}

int main() {
  return 0;
}
