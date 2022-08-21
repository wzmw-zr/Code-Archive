/*************************************************************************
	> File Name: 2.LeetCode6156.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月20日 星期六 22时30分53秒
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

int minimumRecolors(string blocks, int k) {
  int n = blocks.size();
  int l = 0, r = 0;
  int cnt = 0;
  int ans = k;
  while (r < n) {
    cnt += blocks[r] == 'B' ? 1 : 0;
    if (r >= k - 1) {
      ans = min(ans, k - cnt);
      cnt -= blocks[l++] == 'B' ? 1 : 0;
    }
    r++;
  }
  return ans;
}

int main() {
  return 0;
}
