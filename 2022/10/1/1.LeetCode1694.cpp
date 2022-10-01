/*************************************************************************
	> File Name: 1.LeetCode1694.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月01日 星期六 08时03分01秒
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

string reformatNumber(string number) {
  string str = "";
  for (char c : number) {
    if (c >= '0' && c <= '9')
      str += c;
  }
  int n = str.size();
  int group = n / 3;
  int rest = n % 3;
  string ans = "";
  if (rest == 0) {
    for (int i = 0; i < group; i++) {
      if (i > 0) 
        ans += '-';
      ans += str.substr(i * 3, 3);
    }
  } else if (rest == 1) {
    for (int i = 0; i < group - 1; i++) {
      if (i > 0)
        ans += '-';
      ans += str.substr(i * 3, 3);
    }
    if (ans.size() > 0)
      ans += '-';
    ans += str.substr(n - 4, 2);
    ans += '-';
    ans += str.substr(n - 2, 2);
  } else {
    for (int i = 0; i < group; i++) {
      if (i > 0)
        ans += '-';
      ans += str.substr(i * 3, 3);
    }
    if (ans.size() > 0)
      ans += '-';
    ans += str.substr(n - 2, 2);
  }
  return ans;
}

int main() {
  return 0;
}
