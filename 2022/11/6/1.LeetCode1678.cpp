/*************************************************************************
	> File Name: 1.LeetCode1678.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月06日 星期日 10时18分23秒
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

string interpret(string s) {
  string ans = "";
  int ind = 0;
  while (s[ind]) {
    if (s[ind] == 'G') {
      ans += 'G';
      ind++;
    } else if (s[ind] == '(') {
      if (s[ind + 1] == ')') {
        ans += 'o';
        ind += 2;
      } else {
        ans += "al";
        ind += 4;
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
