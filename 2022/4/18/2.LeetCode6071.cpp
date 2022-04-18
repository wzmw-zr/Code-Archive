/*************************************************************************
	> File Name: 2.LeetCode6071.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月18日 星期一 09时58分45秒
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

int minimumRounds(vector<int>& tasks) {
  unordered_map<int, int> mp;
  for (int x : tasks) mp[x]++;
  int ans = 0;
  auto calculate = [](int x) -> int {
    int res = 0;
    if (x & 1) {
      res++;
      x -= 3;
    } 
    res += (x / 6) * 2;
    res += (x - x / 6 * 6) / 2;
    return res;
  };
  for (auto &&[level, cnt] : mp) {
    if (cnt == 1) return -1;
    ans += calculate(cnt);
  }
  return ans;
}

int main() {
  return 0;
}
