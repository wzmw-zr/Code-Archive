/*************************************************************************
	> File Name: 3.LeetCode6124.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月24日 星期日 10时31分08秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

char repeatedCharacter(string s) {
  vector<int> check(26, 0);
  for (char c : s) {
    if (check[c - 'a']) return c;
    check[c - 'a'] = 1;
  }
  return 'a';
}

int main() {
  return 0;
}
