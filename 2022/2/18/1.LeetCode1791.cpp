/*************************************************************************
	> File Name: 1.LeetCode1791.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月18日 星期五 00时09分17秒
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

int findCenter(vector<vector<int>>& edges) {
  int n = edges.size() + 1;
  vector<int> deg(n + 1, 0);
  for (auto &&e : edges) {
    if (++deg[e[0]] >= 2) 
      return e[0];
    if (++deg[e[1]] >= 2) 
      return e[1];
  }
  return -1;
}

int main() {
  return 0;
}
