/*************************************************************************
	> File Name: 2.LeetCode6078.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月29日 星期日 10时30分41秒
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

int rearrangeCharacters(string s, string target) {
  unordered_map<char, int> mp1, mp2;
  for (char c : s) mp1[c]++;
  for (char c : target) mp2[c]++;
  int ans = INT32_MAX;
  for (auto &&[c, cnt] : mp2) {
    ans = min(ans, mp1[c] / cnt);
  }
  return ans;
}

int main() {
  return 0;
}
