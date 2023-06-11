/*************************************************************************
	> File Name: 1.LeetCode6465.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月11日 星期日 10时32分52秒
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

int wzmw_zr = 1;
string smallestString(string s) {
  int n = s.size();
  int ind = 0, last_a = 0;
  int flag = 0;
  while (s[ind] && !flag) {
    while (s[ind] && s[ind] == 'a') {
      last_a = ind;
      ind++;
    }
    while (s[ind] && s[ind] > 'a') {
      flag = 1;
      s[ind]--;
      ind++;
    }
  }
  if (!flag)
    s[last_a] = 'z';
  return s;
}

int main() {
  return 0;
}
