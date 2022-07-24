/*************************************************************************
	> File Name: 2.LeetCode6128.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月23日 星期六 22时32分33秒
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

string bestHand(vector<int>& ranks, vector<char>& suits) {
  int flag = 0;
  for (int i = 0; i < 5; i++) {
    if (suits[i] == suits[0]) continue;
    flag = 1;
    break;
  }
  if (!flag) return "Flush";

  unordered_map<int, int> mp;
  for (int i = 0; i < 5; i++) mp[ranks[i]]++;
  for (auto && [x, cnt] : mp) {
    if (cnt >= 3) return "Three of a Kind";
  }
  for (auto && [x, cnt] : mp) {
    if (cnt == 2) return "Pair";
  }
  return "High Card";
}

int main() {
  return 0;
}
