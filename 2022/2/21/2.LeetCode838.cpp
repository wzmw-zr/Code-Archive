/*************************************************************************
	> File Name: 2.LeetCode838.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月21日 星期一 01时20分43秒
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

string pushDominoes(string dominoes) {
  int n = dominoes.size();
  int l = 0, r = 0;
  while (r < n) {
    while (r < n && dominoes[r] != '.') r++;
    if (r == n) break;
    l = r;
    while (r < n && dominoes[r] == '.') r++;
    if (l == 0 && r == n) break;
    if (l == 0) {
      if (dominoes[r] == 'L') {
        for (int i = 0; i < r; i++) dominoes[i] = dominoes[r];
      }
      l = r;
      continue;
    }
    if (r == n) {
      if (dominoes[l - 1] == 'R') {
        for (int i = l; i < r; i++) dominoes[i] = dominoes[l - 1];
      }
      l = r;
      continue;
    }
    if (dominoes[l - 1] == dominoes[r]) {
      for (int i = l; i < r; i++) dominoes[i] = dominoes[l - 1];
      l = r;
      continue;
    }
    if (dominoes[l - 1] == 'R' && dominoes[r] == 'L') {
      int x = l, y = r - 1;
      while (x < y) {
        dominoes[x++] = dominoes[l - 1];
        dominoes[y--] = dominoes[r];
      }
      l = r;
      continue;
    }
    l = r;
  }
  return dominoes;
}

int main() {
  string dominoes;
  cin >> dominoes;
  cout << pushDominoes(dominoes) << endl;
  return 0;
}
