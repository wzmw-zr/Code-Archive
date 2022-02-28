/*************************************************************************
	> File Name: 1.LeetCode6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月01日 星期二 00时05分19秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string convert(string s, int numRows) {
  if (numRows == 1) return s;
  int n = s.size();
  int chs[numRows][n + 1];
  memset(chs, 0, sizeof(chs));
  int ind = 0;
  int x = 0, y = 0;
  while (ind < n) {
    for (int i = 0; (i < numRows - 1) && ind < n; i++, ind++, x++) chs[x][y] = s[ind];
    for (int i = 0; (i < numRows - 1) && ind < n; i++, ind++, x--, y++) chs[x][y] = s[ind];
  }
  string ans = "";
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j <= n; j++) {
      if (chs[i][j]) ans += chs[i][j];
    }
  }
  return ans;
}

int main() {
  string s;
  int numRows;
  cin >> s >> numRows;
  cout << s << " " << numRows << endl;
  cout << convert(s, numRows) << endl;
  return 0;
}
