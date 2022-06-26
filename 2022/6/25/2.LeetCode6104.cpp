/*************************************************************************
	> File Name: 2.LeetCode6104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月25日 星期六 22时32分18秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int countAsterisks(string s) {
  int flag = 0;
  int temp = 0;
  int ans = 0;
  for (char c : s) {
    if (c == '*') temp++;
    if (c == '|') {
      if (flag == 1) flag = 0, temp = 0;
      else flag = 1, ans += temp, temp = 0;
    }
  }
  return ans + temp;
}

int main() {
  return 0;
}
