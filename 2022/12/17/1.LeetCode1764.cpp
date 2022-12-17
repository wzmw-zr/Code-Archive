/*************************************************************************
	> File Name: 1.LeetCode1764.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月17日 星期六 11时21分50秒
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

bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
  int n = nums.size();
  int ind = 0;
  for (auto && g : groups) {
    if (ind >= n)
      return false;
    while (ind < n) {
      int m = g.size();
      int flag = 0;
      for (int i = 0; i < m; i++) {
        if (g[i] != nums[ind + i]) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        ind++;
        if (ind >= n)
          return false;
      } else {
        ind += m;
        break;
      }
    }
  }
  return true;
}

int main() {
  return 0;
}
