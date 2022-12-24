/*************************************************************************
	> File Name: 3.LeetCode6273.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月24日 星期六 22时35分39秒
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

int captureForts(vector<int>& forts) {
  int n = forts.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (forts[i] != 1)
      continue;
    int l = i - 1;
    while (l >= 0 && forts[l] == 0)
      l--;
    if (l >= 0 && forts[l] == -1)
      ans = max(ans, i - l - 1);
    int r = i + 1;
    while (r < n && forts[r] == 0)
      r++;
    if (r < n && forts[r] == -1)
      ans = max(ans, r - i - 1);
  }
  return ans;
}

int main() {
  return 0;
}
