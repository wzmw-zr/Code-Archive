/*************************************************************************
	> File Name: 3.LeetCode6196.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月01日 星期日 10时42分50秒
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

int minimumPartition(string s, int k) {
  int n = s.size();
  int ind = 0;
  int cnt = 0;
  while (ind < n) {
    string str = "";
    while (ind < n) {
      str += s[ind];
      if (stol(str) <= k) {
        ind++;
      } else {
        if (str.size() == 1)
          return -1;
        cnt++;
        break;
      }
    }
    if (ind == n)
      cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
