/*************************************************************************
	> File Name: 1.LeetCode481.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月31日 星期一 10时43分31秒
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

int magicalString(int n) {
  string s = "122";
  int ind_1 = 2, ind_2 = 3;
  while (s.size() < n) {
    if (s[ind_1] == '1') {
      s += s[ind_2 - 1] == '1' ? '2' : '1';
      ind_1 += 1;
      ind_2 += 1;
    } else {
      s += s[ind_2 - 1] == '1' ? '2' : '1';
      s += s[ind_2 - 1] == '1' ? '2' : '1';
      ind_1 += 1;
      ind_2 += 2;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += s[i] == '1' ? 1 : 0;
  return ans;
}

int main() {
  return 0;
}
