/*************************************************************************
	> File Name: 1.LeetCode2569.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月26日 星期三 10时22分18秒
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

struct SegTree {
  int n;
  vector<int> nums;
  vector<int> vals;
  vector<int> lazy;

  SegTree(vector<int> &_nums) : nums(_nums), vals(vector<int>(4 * _nums.size() + 10, 0)), lazy(vector<int>(4 * _nums.size() + 10, 0)), n(_nums.size()) {
    build(0, 0, n - 1);
  }

  void build(int ind, int l, int r) {
    if (l == r) {
      vals[ind] = nums[l];
      return ;
    }
    int mid = (l + r) / 2;
    build(ind * 2 + 1, l, mid);
    build(ind * 2 + 2, mid + 1, r);
    vals[ind] = vals[ind * 2 + 1] + vals[ind * 2 + 2];
  }

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    if (lazy[ind] == 0)
      return ;
    lazy[ind * 2 + 1] = !lazy[ind * 2 + 1];
    lazy[ind * 2 + 2] = !lazy[ind * 2 + 2];
    lazy[ind] = 0;
    int mid = (l + r) / 2;
    vals[ind * 2 + 1] = mid - l + 1 - vals[ind * 2 + 1];
    vals[ind * 2 + 2] = r - mid - vals[ind * 2 + 2];
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind] = vals[ind * 2 + 1] + vals[ind * 2 + 2];
  }

  void update(int ind, int l, int r, int s, int t) {
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      vals[ind] = (r - l + 1 - vals[ind]);
      lazy[ind] ^= 1;
      return ;
    }
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    if (s <= mid)
      update(ind * 2 + 1, l, mid, s, t);
    if (t >= mid + 1)
      update(ind * 2 + 2, mid + 1, r, s, t);
    push_up(ind, l, r);
  }

  void update(int s, int t) {
    update(0, 0, n - 1, s, t);
  }

  int query(int ind, int l, int r, int s, int t) {
    if (r < s || l > t)
      return 0;
    if (l >= s && r <= t)
      return vals[ind];
    push_down(ind, l, r);
    int ans = 0;
    int mid = (l + r) / 2;
    if (s <= mid)
      ans += query(ind * 2 + 1, l, mid, s, t);
    if (t >= mid + 1)
      ans += query(ind * 2 + 2, mid + 1, r, s, t);
    push_up(ind, l, r);
    return ans;
  }

  int query(int s, int t) {
    return query(0, 0, n - 1, s, t);
  }
};

vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
  int n = nums1.size();
  SegTree segtree(nums1);
  long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
  vector<long long> ans;
  for (auto && q : queries) {
    if (q[0] == 1) {
      segtree.update(q[1], q[2]);
    } else if (q[0] == 2) {
      sum += 1LL * segtree.query(0, n - 1) * q[1];
    } else {
      ans.push_back(sum);
    }
  }
  return ans;
}

int main() {
  return 0;
}
