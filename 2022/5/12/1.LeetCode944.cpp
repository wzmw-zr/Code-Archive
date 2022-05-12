/*************************************************************************
	> File Name: 1.LeetCode944.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月12日 星期四 08时40分56秒
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

int minDeletionSize(vector<string>& strs) {
  int m = strs.size(), n = strs[0].size();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (strs[j][i] < strs[j - 1][i]) {
        cnt++;
        break;
      }
    }
  }
  return cnt;
}

int main() {
  return 0;
}
