/*************************************************************************
	> File Name: 1.LeetCode2337.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月21日 星期一 08时38分50秒
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

bool canChange(string start, string target) {
  int n = start.size();
  vector<int> s_l, t_l, s_r, t_r;
  for (int i = 0;  i < n; i++) {
    if (start[i] == 'L')
      s_l.push_back(i);
    if (start[i] == 'R')
      s_r.push_back(i);
    if (target[i] == 'L')
      t_l.push_back(i);
    if (target[i] == 'R')
      t_r.push_back(i);
  }
  if (s_l.size() != t_l.size() || s_r.size() != t_r.size())
    return false;
  vector<int> pre_r(n + 1, 0), suf_l(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pre_r[i + 1] = pre_r[i];
    if (start[i] == 'R')
      pre_r[i + 1]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    suf_l[i] = suf_l[i + 1];
    if (target[i] == 'L')
      suf_l[i]++;
  }
  for (int i = 0; i < s_l.size(); i++) {
    int ind_1 = s_l[i], ind_2 = t_l[i];
    if (ind_1 < ind_2)
      return false;
    if (pre_r[ind_1 + 1] - pre_r[ind_2])
      return false;
  }
  for (int i = 0; i < s_r.size(); i++) {
    int ind_1 = s_r[i], ind_2 = t_r[i];
    if (ind_1 > ind_2)
      return false;
    if (suf_l[ind_1] - suf_l[ind_2 + 1])
      return false;
  }
  return true;
}

int main() {
  return 0;
}
