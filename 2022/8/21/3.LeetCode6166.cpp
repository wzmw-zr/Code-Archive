/*************************************************************************
	> File Name: 3.LeetCode6166.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月21日 星期日 10时37分49秒
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

string largestPalindromic(string num) {
  map<int, int> mp;
  for (char c : num)
    mp[c - '0']++;
  vector<int> nums1;
  for (auto && [x, cnt] : mp) {
    if (cnt >= 2) 
      nums1.push_back(x);
  }
  int n = nums1.size();
  string prefix = "";
  if (n > 0 && nums1[n - 1] != 0) {
    for (int i = n - 1; i >= 0; i--) {
      for (int cnt = 1; cnt <= mp[nums1[i]] / 2; cnt++) 
        prefix += ('0' + nums1[i]);
      mp[nums1[i]] -= (mp[nums1[i]] / 2) * 2;
    }
  }
  nums1 = vector<int>(0);
  vector<int> nums2;
  for (auto && [x, cnt] : mp) {
    if (cnt == 1)
      nums2.push_back(x);
    else if (cnt > 1)
      nums1.push_back(x);
  }
  string mid = "";
  int m = nums2.size();
  if (m > 0) 
    mid += ('0' + nums2[m - 1]);
  else if (nums1.size() > 0)
    mid += '0';
  string ans = prefix + mid;
  reverse(prefix.begin(), prefix.end());
  ans += prefix;
  return ans;
}

int main() {
  string num;
  cin >> num;
  cout << largestPalindromic(num) << endl;
  return 0;
}
