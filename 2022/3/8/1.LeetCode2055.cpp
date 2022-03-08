/*************************************************************************
	> File Name: 1.LeetCode2055.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月08日 星期二 10时38分16秒
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

int find_first_ge(vector<int> &inds, int x) {
  int l = 0, r = static_cast<int>(inds.size()) - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (inds[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return l;
}

int find_last_le(vector<int> &inds, int x) {
  int l = 0, r = static_cast<int>(inds.size()) - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (inds[mid] <= x) l = mid;
    else r = mid - 1;
  }
  return l;
}

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
  int n = s.size();
  vector<int> inds;
  for (int i = 0; i < n; i++) {
    if (s[i] == '|') inds.push_back(i);
  }
  vector<int> ans;
  for (auto q : queries) {
    int l = find_first_ge(inds, q[0]);
    int r = find_last_le(inds, q[1]);
    if (r <= l) ans.push_back(0);
    else ans.push_back(inds[r] - inds[l] - (r - l));
  }
  return ans;
}

int main() {
  return 0;
}
