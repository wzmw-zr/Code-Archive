/*************************************************************************
	> File Name: 1.LeetCode_mianshi_1705.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月11日 星期六 10时02分11秒
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

vector<string> findLongestSubarray(vector<string>& array) {
  int n = array.size();
  unordered_map<int, int> mp_1;
  unordered_map<int, int> mp_2;
  mp_1[0] = -1;
  mp_2[0] = -1;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    x += (array[i][0] >= '0' && array[i][0] <= '9') ? 1 : 0;
    y += (array[i][0] >= '0' && array[i][0] <= '9') ? 0 : 1;
    if (!mp_1.count(x - y))
      mp_1[x - y] = i;
    mp_2[x - y] = i;
  }
  int len = 0;
  for (auto && [x, ind] : mp_1)
    len = max(len, mp_2[x] - ind);
  int left = n - 1;
  for (auto && [x, ind] : mp_1) {
    if (mp_2[x] - ind == len)
      left = min(left, ind + 1);
  }
  vector<string> ans;
  for (int i = left; i < left + len; i++)
    ans.push_back(array[i]);
  return ans;
}

int main() {
  return 0;
}
