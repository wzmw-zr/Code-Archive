/*************************************************************************
	> File Name: 1.LeetCode761.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月08日 星期一 10时05分39秒
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
#include <numeric>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string makeLargestSpecial(string s) {
  int n = s.size();
  if (n <= 2) return s;
  int cnt = 0;
  int left = 0;
  vector<string> strs;
  for (int i = 0; i < n; i++) {
    cnt += s[i] == '1' ? 1 : -1;
    if (cnt == 0) {
      strs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
      left = i + 1;
    }
  }
  sort(strs.begin(), strs.end(), greater<string>());
  string ans = accumulate(strs.begin(), strs.end(), ""s);
  return ans;
}

int main() {
  return 0;
}
