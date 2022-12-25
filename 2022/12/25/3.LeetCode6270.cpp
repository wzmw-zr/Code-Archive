/*************************************************************************
	> File Name: 3.LeetCode6270.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月25日 星期日 10时41分07秒
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

bool check(vector<int> &nums, int k) {
  for (auto && x : nums) {
    if (x < k)
      return false;
  }
  return true;
}

int takeCharacters(string s, int k) {
  if (k == 0)
    return 0;
  int n = s.size();
  int ans = INT32_MAX;
  int l = 0, r = 0;
  vector<int> cnts(3, 0);
  while (r < n) {
    cnts[s[r] - 'a']++;
    if (check(cnts, k))
      ans = min(ans, r + 1);
    r++;
  }
  l = n - 1, r = n - 1;
  cnts = vector<int>(3, 0);
  while (l >= 0) {
    cnts[s[l] - 'a']++;
    if (check(cnts, k))
      ans = min(ans, n - l);
    l--;
  }
  s += s;
  l = 0, r = 0;
  cnts = vector<int>(3, 0);
  while (l < n && r < 2 * n) {
    cnts[s[r] - 'a']++;
    if (check(cnts, k)) {
      while (l < n && check(cnts, k)) {
        if (r >= n) {
          if (r - l + 1 <= n)
            ans = min(ans, r - l + 1);
        }
        cnts[s[l] - 'a']--;
        l++;
      }
    }
    r++;
  }
  return ans == INT32_MAX ? -1 : ans;
}

int main() {
  return 0;
}
