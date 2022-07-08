/*************************************************************************
	> File Name: 1.LeetCode1217.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月08日 星期五 09时12分38秒
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

int minCostToMoveChips(vector<int>& position) {
  int n = position.size();
  unordered_set<int> st;
  for (int x : position) st.insert(x);
  int ans = INT32_MAX;
  for (int x : st) {
    int cnt = 0;
    for (int y : position) {
      if (abs(x - y) & 1) cnt++;
    }
    ans = min(ans, cnt);
  }
  return ans;
}

int main() {
  return 0;
}
