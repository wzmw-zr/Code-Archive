/*************************************************************************
	> File Name: 2.LeetCode5299.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月14日 星期六 22时31分16秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int divisorSubstrings(int num, int k) {
  string s = to_string(num);
  int n = s.size();
  int cnt = 0;
  for (int i = 0; i + k <= n; i++) {
    string t = s.substr(i, k);
    int x = stoi(t);
    if (x == 0) continue;
    if (num % x == 0) cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
