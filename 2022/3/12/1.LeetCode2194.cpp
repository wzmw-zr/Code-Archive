/*************************************************************************
	> File Name: 1.LeetCode2194.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月12日 星期六 19时24分48秒
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

vector<string> cellsInRange(string s) {
  char c1 = s[0], c2 = s[3], r1 = s[1], r2 = s[4];
  vector<string> ans;
  for (int j = 0; c1 + j <= c2; j++) {
    for (int i = 0; r1 + i <= r2; i++) {
      string temp;
      temp += c1 + j;
      temp += r1 + i;
      ans.push_back(temp);
    }
  }
  return ans;
}

int main() {
  return 0;
}
