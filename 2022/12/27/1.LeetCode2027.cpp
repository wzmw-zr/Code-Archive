/*************************************************************************
	> File Name: 1.LeetCode2027.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月27日 星期二 00时20分10秒
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

int minimumMoves(string s) {
  int n = s.size();
  int ind = 0;
  int ans = 0;
  while (s[ind]) {
    if (s[ind] == 'X') {
      for (int i = 0; i < 3 && (ind + i < n); i++) 
        s[ind + i] = 'O';
      ans++;
    }
    ind++;
  }
  return ans;
}

int main() {
  return 0;
}
