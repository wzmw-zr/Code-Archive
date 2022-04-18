/*************************************************************************
	> File Name: 1.LeetCode6070.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月18日 星期一 09时52分58秒
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

string digitSum(string s, int k) {
  while (s.size() > k) {
    string temp;
    int ind = 0;
    while (s[ind]) {
      int t = 0;
      for (int i = 0; i < k && s[ind]; i++, ind++) t += s[ind] - '0';
      temp += to_string(t);
    }
    s = temp;
  }
  return s;
}

int main() {
  return 0;
}
