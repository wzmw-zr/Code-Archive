/*************************************************************************
	> File Name: 3.LeetCode6157.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月20日 星期六 22时38分07秒
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

int secondsToRemoveOccurrences(string s) {
  int ticket = 0;
  int n = s.size();
  while (1) {
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '0' && s[i + 1] == '1') {
        flag = 1;
        break;
      }
    }
    if (!flag) break;
    for (int i = 0; i < n - 1; ) {
      if (s[i] == '0' && s[i + 1] == '1') {
        swap(s[i], s[i + 1]);
        i += 2;
      } else {
        i++;
      }
    }
    ticket++;
  }
  return ticket;
}

int main() {
  return 0;
}
