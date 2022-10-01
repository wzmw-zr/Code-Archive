/*************************************************************************
	> File Name: 4.LeetCode6213.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月01日 星期六 22时51分17秒
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

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size(), m = nums2.size();
  vector<long> cnts_1(32, 0), cnts_2(32, 0);
  for (int x : nums1) {
    for (int i = 0; i <= 30; i++) {
      if (x & (1 << i))
        cnts_1[i]++;
    }
  }
  for (int x : nums2) {
    for (int i = 0; i <= 30; i++) {
      if (x & (1 << i))
        cnts_2[i]++;
    }
  }
  vector<int> res(32, 0);
  for (int i = 0; i <= 30; i++) {
    long t = cnts_1[i] * (m - cnts_2[i]) + (n - cnts_1[i]) * cnts_2[i];
    res[i] = t % 2;
  }
  int ans = 0;
  for (int i = 0; i <= 30; i++)
    ans += res[i] * (1 << i);
  return ans;
}

int main() {
  return 0;
}
