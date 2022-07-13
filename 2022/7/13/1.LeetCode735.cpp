/*************************************************************************
	> File Name: 1.LeetCode735.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月13日 星期三 09时27分36秒
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

vector<int> asteroidCollision(vector<int>& asteroids) {
  vector<int> left;
  vector<int> right;
  for (int x : asteroids) {
    if (x > 0) right.push_back(x);
    else {
      int flag = 0;
      while (right.size()) {
        int t = *(right.rbegin());
        if (t <= abs(x)) 
          right.pop_back();
        if (t >= abs(x)) {
          flag = 1;
          break;
        }
      }
      if (!flag) left.push_back(x);
    }
  }
  vector<int> ans;
  for (int x : left) ans.push_back(x);
  for (int x : right) ans.push_back(x);
  return ans;
}

int main() {
  return 0;
}
