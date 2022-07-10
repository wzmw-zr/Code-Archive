/*************************************************************************
	> File Name: 2.LeetCode6112.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月10日 星期日 10时34分19秒
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

int fillCups(vector<int>& amount) {
  priority_queue<int> que;
  for (int x : amount) {
    if (x > 0) que.push(x);
  }
  int ans = 0;
  while (!que.empty()) {
    int x = que.top();
    que.pop();
    if (!que.empty()) {
      int y = que.top();
      que.pop();
      ans++, x--, y--;
      if (x) que.push(x);
      if (y) que.push(y);
    } else {
      ans += x;
    }
  }
  return ans;
}

int main() {
  return 0;
}
