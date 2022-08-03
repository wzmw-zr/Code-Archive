/*************************************************************************
	> File Name: 1.LeetCode899.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月03日 星期三 10时06分43秒
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

string orderlyQueue(string s, int k) {
  if (k > 1) {
    sort(s.begin(), s.end());
    return s;
  }
  int n = s.size();
  vector<string> strs;
  for (int i = 0; i < n; i++) 
    strs.push_back(s.substr(i + 1) + s.substr(0, i + 1));
  sort(strs.begin(), strs.end());
  return strs[0];
}

int main() {
  return 0;
}
