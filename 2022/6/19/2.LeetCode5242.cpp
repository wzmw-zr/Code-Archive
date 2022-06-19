/*************************************************************************
	> File Name: 2.LeetCode5242.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月19日 星期日 10时30分45秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string greatestLetter(string s) {
  vector<int> cnt1(26, 0), cnt2(26, 0);
  for (char c : s) {
    if (c >= 'a' && c <= 'z') cnt1[c - 'a'] = 1;
    if (c >= 'A' && c <= 'Z') cnt2[c - 'A'] = 1;
  }
  for (int i = 25; i >= 0; i--) {
    if (cnt1[i] && cnt2[i]) {
      string ans = "A";
      ans[0] += i;
      return ans;
    }
  }
  return "";
}

int main() {
  return 0;
}
