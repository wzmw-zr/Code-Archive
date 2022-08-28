/*************************************************************************
	> File Name: 3.LeetCode6161.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月28日 星期日 10时37分31秒
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

string removeStars(string s) {
  string ans = "";
  for (char c : s) {
    if (c != '*') 
      ans.push_back(c);
    else
      ans.pop_back();
  }
  return ans;
}

int main() {
  return 0;
}
