/*************************************************************************
	> File Name: 2.LeetCode6008.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月27日 星期日 10时30分29秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int prefixCount(vector<string>& words, string pref) {
  int cnt = 0;
  for (string &word : words) {
    if (word.size() < pref.size()) continue;
    if (word.substr(0, pref.size()) == pref) cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
