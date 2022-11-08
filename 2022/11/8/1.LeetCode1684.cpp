/*************************************************************************
	> File Name: 1.LeetCode1684.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月08日 星期二 09时28分58秒
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

int countConsistentStrings(string allowed, vector<string>& words) {
  unordered_set<char> st(allowed.begin(), allowed.end());
  int ans = 0;
  for (auto && word : words) {
    int flag = 1;
    for (char c : word) {
      if (!st.count(c)) {
        flag = 0;
        break;
      }
    }
    ans += flag;
  }
  return ans;
}

int main() {
  return 0;
}
