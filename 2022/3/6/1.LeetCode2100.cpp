/*************************************************************************
	> File Name: 1.LeetCode2100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月06日 星期日 01时30分33秒
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

// WA
vector<int> goodDaysToRobBank(vector<int>& security, int time) {
  int n = security.size();
  vector<int> pre(n + 1, 1);
  vector<int> suf(n + 1, 1);
  pre[0] = 0;
  for (int i = 1; i < n - 1; i++) {
    if (security[i] <= security[i - 1]) pre[i + 1] = pre[i] + 1;
  }
  suf[n - 1] = 0;
  for (int i = n - 2; i >= 1; i--) {
    if (security[i] <= security[i + 1]) suf[i - 1] = suf[i] + 1;
  }
  vector<int> ans;
  for (int i = time; i < n - time; i++) {
    if (pre[i] >= time && suf[i] >= time) ans.push_back(i);
  }
  return ans;
}

int main() {
  return 0;
}
