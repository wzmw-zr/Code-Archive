/*************************************************************************
	> File Name: 2.LeetCode2506.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月19日 星期一 10时51分24秒
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

int similarPairs(vector<string>& words) {
  int n = words.size();
  vector<set<char>> sts(n);
  for (int i = 0; i < n; i++) {
    for (char c : words[i])
      sts[i].insert(c);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += sts[i] == sts[j] ? 1 : 0;
    }
  }
  return ans;
}

int main() {
  return 0;
}
