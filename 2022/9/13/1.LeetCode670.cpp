/*************************************************************************
	> File Name: 1.LeetCode670.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月13日 星期二 09时34分47秒
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

int maximumSwap(int num) {
  string s = to_string(num);
  int n = s.size();
  int ans = num;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(s[i], s[j]);
      int t = stoi(s);
      ans = max(ans, t);
      swap(s[i], s[j]);
    }
  }
  return ans;
}

int main() {
  return 0;
}
