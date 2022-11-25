/*************************************************************************
	> File Name: 1.LeetCode809.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月25日 星期五 09时31分39秒
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

using PCI = pair<char, int>;

int check(string &s1, string &s2) {
  vector<PCI> nodes_1, nodes_2;
  int l = 0, r = 0;
  while (s1[r]) {
    while (s1[r] && s1[r] == s1[l])
      r++;
    nodes_1.push_back(PCI(s1[l], r - l));
    l = r;
  }
  l = 0, r = 0;
  while (s2[r]) {
    while (s2[r] && s2[r] == s2[l])
      r++;
    nodes_2.push_back(PCI(s2[l], r - l));
    l = r;
  }
  if (nodes_1.size() != nodes_2.size())
    return 0;
  int n = nodes_1.size();
  for (int i = 0; i < n; i++) {
    if (nodes_1[i].first != nodes_2[i].first)
      return 0;
    if (nodes_1[i].second == nodes_2[i].second)
      continue;
    if (nodes_1[i].second < nodes_2[i].second)
      return 0;
    if (nodes_1[i].second < 3)
      return 0;
  }
  return 1;
}

int expressiveWords(string s, vector<string>& words) {
  int ans = 0;
  for (string & word : words)
    ans += check(s, word);
  return ans;
}

int main() {
  return 0;
}
