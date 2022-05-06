/*************************************************************************
	> File Name: 3.LeetCode6048.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月01日 星期日 10时36分40秒
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

int minimumCardPickup(vector<int>& cards) {
  int n = cards.size();
  unordered_map<int, int> mp;
  int ans = INT32_MAX;
  for (int i = 0; i < n; i++) {
    if (mp.count(cards[i])) ans = min(ans, i - mp[cards[i]] + 1);
    mp[cards[i]] = i;
  }
  return ans == INT32_MAX ? -1 : ans;
}

int main() {
  return 0;
}
