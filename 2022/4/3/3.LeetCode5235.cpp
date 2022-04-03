/*************************************************************************
	> File Name: 3.LeetCode5235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月03日 星期日 10时45分43秒
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

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
  vector<vector<int>> ans(2, vector<int>(0));
  map<int, int> winner, loser;
  for (auto &&x : matches) {
    winner[x[0]]++;
    loser[x[1]]++;
  }
  for (auto &&[x, cnt] : winner) {
    if (loser.count(x)) continue;
    ans[0].push_back(x);
  }
  for (auto &&[x, cnt] : loser) {
    if (cnt == 1) ans[1].push_back(x);
  }
  return ans;
}

int main() {
  return 0;
}
