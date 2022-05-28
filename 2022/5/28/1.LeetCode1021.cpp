/*************************************************************************
	> File Name: 1.LeetCode1021.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月28日 星期六 09时04分38秒
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

string removeOuterParentheses(string s) {
  int n = s.size();
  int l = 0, r = 0;
  string ans = "";
  do {
    int cnt = 0;
    do {
      cnt += s[r] == '(' ? 1 : -1;
      r++;
    } while (r < n && cnt != 0);
    ans += s.substr(l + 1, r - l - 2);
    l = r;
  } while (r < n);
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << removeOuterParentheses(s) << endl;
  return 0;
}
