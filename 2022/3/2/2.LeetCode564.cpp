/*************************************************************************
	> File Name: 2.LeetCode564.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月02日 星期三 01时20分39秒
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


int find_last_lt(vector<long> &nums, long t) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (nums[mid] < t) l = mid;
    else r = mid - 1;
  }
  return l;
}

int find_first_gt(vector<long> &nums, long t) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] > t) r = mid;
    else l = mid + 1;
  }
  return l;
}

void dfs(vector<long> &nums, string &n, int l, int r) {
  if (l > r) {
    if (n.size() > 1 && n[0] == '0') return ;
    nums.push_back(stol(n));
    return ;
  }
  char ch_l = n[l];
  char ch_r = n[r];
  set<char> st;
  n[l] = n[r] = ch_l;
  dfs(nums, n, l + 1, r - 1);
  st.insert(ch_l);
  if (ch_l > '0') {
    n[l] = n[r] = ch_l - 1;
    dfs(nums, n, l + 1, r - 1);
    st.insert(ch_l - 1);
  }
  if (ch_l < '9') {
    n[l] = n[r] = ch_l + 1;
    dfs(nums, n, l + 1, r - 1);
    st.insert(ch_l + 1);
  }

  n[l] = n[r] = ch_r;
  if (!st.count(ch_r)) dfs(nums, n, l + 1, r - 1);
  if (ch_r > '0') {
    if (!st.count(ch_r - 1)) {
      n[l] = n[r] = ch_r - 1;
      dfs(nums, n, l + 1, r - 1);
    }
  }
  if (ch_r < '9') {
    if (!st.count(ch_r + 1)) {
      n[l] = n[r] = ch_r + 1;
      dfs(nums, n, l + 1, r - 1);
    }
  }
}

string nearestPalindromic(string n) {
  vector<long> nums;
  long t = stol(n);
  dfs(nums, n, 0, n.size() - 1);
  set<long> st;
  if (n.size() >= 2) {
    string s = "";
    for (int i = 0; i < n.size() - 1; i++) s += '9';
    st.insert(stol(s));
  }
  string s = "1";
  for (int i = 0; i < n.size() - 1; i++) s += '0';
  s += "1";
  st.insert(stol(s));
  for (long x : nums) st.insert(x);
  nums = vector<long>(st.begin(), st.end());
  int last_lt = find_last_lt(nums, t);
  int first_gt = find_first_gt(nums, t);
  if (abs(nums[last_lt] - t) <= abs(nums[first_gt] - t)) return to_string(nums[last_lt]);
  return to_string(nums[first_gt]);
}

int main() {
  string n;
  cin >> n;
  cout << nearestPalindromic(n) << endl;
  return 0;
}
