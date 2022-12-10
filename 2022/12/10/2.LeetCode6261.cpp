/*************************************************************************
	> File Name: 2.LeetCode6261.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月10日 星期六 22时31分43秒
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

int change(string &s) {
  for (char c : s) {
    if (!(c >= '0' && c <= '9'))
      return s.size();
  }
  return stoi(s);
}

int maximumValue(vector<string>& strs) {
  int mmax = 0;
  for (string & s : strs)
    mmax = max(mmax, change(s));
  return mmax;
}

int main() {
  return 0;
}
