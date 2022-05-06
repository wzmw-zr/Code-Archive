/*************************************************************************
	> File Name: 2.LeetCode6047.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月01日 星期日 10时31分56秒
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

string generate(string &s, int ind) {
  string res = "";
  for (int i = 0; s[i]; i++) {
    if (i == ind) continue;
    res += s[i];
  }
  return res;
}

string removeDigit(string number, char digit) {
  vector<int> inds;
  for (int i = 0; number[i]; i++) {
    if (number[i] == digit) inds.push_back(i);
  }
  vector<string> res;
  for (auto ind : inds) res.push_back(generate(number, ind));
  sort(res.begin(), res.end());
  return *res.rbegin();
}

int main() {
  return 0;
}
