/*************************************************************************
	> File Name: 1.LeetCode1235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月22日 星期六 09时47分40秒
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

struct Job {
  int start;
  int end;
  int money;

  Job() = default;
  Job(int start, int end, int money) : start(start), end(end), money(money) {}

  bool operator<(const struct Job &that) const {
    return this->end == that.end ? this->start < that.start : this->end < that.end;
  }
};

struct SegTree {
  int n;
  vector<int> vals;
  vector<int> lazy;

  SegTree() = default;
  SegTree(int n) : n(n), vals(vector<int>(4 * n + 10, 0)), lazy(vector<int>(4 * n + 10, 0)) {}

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind * 2 + 1] = max(vals[ind * 2 + 1], lazy[ind]);
    vals[ind * 2 + 2] = max(vals[ind * 2 + 2], lazy[ind]);
    lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
    lazy[ind * 2 + 2] = max(lazy[ind * 2 + 2], lazy[ind]);
    lazy[ind] = 0;
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind] = max(vals[ind * 2 + 1], vals[ind * 2 + 2]);
  }

  void update(int ind, int l, int r, int s, int t, int val) {
    if (l > t || r < s)
      return ;
    if (l >= s && r <= t) {
      vals[ind] = max(vals[ind], val);
      lazy[ind] = max(lazy[ind], val);
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
    update(0, 0, n, s, t, val);
  }

  int query(int ind, int l, int r, int s, int t) {
    if (l > t || r < s) 
      return 0;
    if (l >= s && r <= t)
      return vals[ind];
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    int ans = 0;
    if (s <= mid)
      ans = max(ans, query(ind * 2 + 1, l, mid, s, t));
    if (t > mid)
      ans = max(ans, query(ind * 2 + 2, mid + 1, r, s, t));
    push_up(ind, l, r);
    return ans;
  }

  int query(int s, int t) {
    return query(0, 0, n, s, t);
  }
};

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  int n = startTime.size();
  vector<Job> jobs;
  for (int i = 0; i < n; i++)
    jobs.emplace_back(startTime[i],endTime[i], profit[i]);
  sort(jobs.begin(), jobs.end());

  set<int> st;
  for (int x : startTime)
    st.insert(x);
  for (int x : endTime)
    st.insert(x);
  int ind = 1;
  unordered_map<int, int> mp;
  for (int x : st)
    mp[x] = ind++;

  SegTree segtree(ind + 10);
  for (auto && job : jobs) {
    int mmax = segtree.query(0, mp[job.start]);
    segtree.update(mp[job.end], ind, mmax + job.money);
  }
  return segtree.query(0, ind);
}

int main() {
  return 0;
}
