/*************************************************************************
	> File Name: 1.LeetCode1247.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月25日 星期六 10时29分18秒
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

int minimumSwap(string s1, string s2) {
  int xy = 0, yx = 0;
  for (int i = 0; s1[i]; i++) {
    if (s1[i] == s2[i])
      continue;
    if (s1[i] == 'x')
      xy++;
    else
      yx++;
  }
  if (!(xy & 1) && !(yx & 1))
    return xy / 2 + yx / 2;
  if ((xy & 1) && (yx & 1))
    return (xy - 1) / 2 + (yx - 1) / 2 + 2;
  return -1;
}

int main() {
  return 0;
}
