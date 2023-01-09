/*************************************************************************
	> File Name: 1.LeetCode1806.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月09日 星期一 11时15分05秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int reinitializePermutation(int n) {
  vector<int> cnts;
  for (int i = 0; i < n; i++) {
    int x = i;
    int cnt = 0;
    do {
      x = (x & 1) ? (n / 2 + (x - 1) / 2) : x / 2;
      cnt++;
    } while (x != i);
    cnts.push_back(cnt);
  }
  function<int(int, int)> gcd = [&](int x, int y) -> int {
    return y == 0 ? x : gcd(y, x % y);
  };
  int ans = cnts[0];
  for (int i = 1; i < n; i++)
    ans = 1L * ans * cnts[i] / gcd(ans, cnts[i]);
  return ans;
}

int main() {
  return 0;
}
