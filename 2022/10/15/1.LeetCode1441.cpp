/*************************************************************************
	> File Name: 1.LeetCode1441.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月15日 星期六 09时14分55秒
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

vector<string> buildArray(vector<int>& target, int n) {
  vector<string> ans;
  int m = target.size();
  for (int i = 1; i < target[0]; i++) {
    ans.push_back("Push");
    ans.push_back("Pop");
  }
  for (int i = 0; i < m - 1; i++) {
    ans.push_back("Push");
    for (int j = 0; j < (target[i + 1] - target[i] - 1); j++) {
      ans.push_back("Push");
      ans.push_back("Pop");
    }
  }
  ans.push_back("Push");
  return ans;
}

int main() {
  return 0;
}
