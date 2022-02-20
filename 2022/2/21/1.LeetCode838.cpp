/*************************************************************************
	> File Name: 1.LeetCode838.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月21日 星期一 00时17分13秒
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
  vector<int> inds;
  for (int i = 0; i < n; i++) {
    if (dominoes[i] != '.') inds.push_back(i);
  }
  while (inds.size() > 0) {
    // for (int ind : inds) cout << "(" << ind << ", " << dominoes[ind] << "), ";
    // cout << endl;
    // cout << dominoes << endl;
    unordered_map<int, vector<char>> mp;
    for (int ind : inds) {
      if (dominoes[ind] == 'L') {
        if (ind == 0 || dominoes[ind - 1] != '.') continue;
        if (!mp.count(ind - 1)) mp[ind - 1] = vector<char>();
        mp[ind - 1].push_back('L');
      } else {
        if (ind == n - 1 || dominoes[ind + 1] != '.') continue;
        if (!mp.count(ind + 1)) mp[ind + 1] = vector<char>();
        mp[ind + 1].push_back('R');
      }
    }
    if (mp.empty()) break;
    vector<int> temp;
    for (auto &&[ind, chs] : mp) {
      if (chs.size() != 1) continue;
      dominoes[ind] = chs[0];
      temp.push_back(ind);
    }
    inds = temp;
  }
  return dominoes;
}

int main() {
  string dominoes;
  cin >> dominoes;
  cout << pushDominoes(dominoes) << endl;
  return 0;
}
