/*************************************************************************
	> File Name: 1.LeetCode1784.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月03日 星期一 09时20分53秒
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

bool checkOnesSegment(string s) {
  int n = s.size();
  int ind = 0;
  int cnt = 0;
  while (s[ind]) {
    while (s[ind] && s[ind] == '0') 
      ind++;
    if (s[ind] && s[ind]  == '1') 
      cnt++;
    while (s[ind] && s[ind] == '1')
      ind++;
  }
  return cnt <= 1;
}

int main() {
  return 0;
}
