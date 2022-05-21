/*************************************************************************
	> File Name: 1.LeetCode2147.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月21日 星期六 16时22分44秒
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

long MOD = 1e9 + 7;

int numberOfWays(string corridor) {
  int cnt = 0;
  for (char c : corridor) cnt += c == 'S' ? 1 : 0;
  if ((cnt < 2) || (cnt & 1)) return 0;
  long ans = 1;
  int n = corridor.size();
  int ind = 0;
  int pre = 0;
  while (ind < n) {
    while (ind < n && pre < 2) {
      pre += corridor[ind] == 'S' ? 1 : 0;
      ind++;
    }
    long dis = 1;
    while (ind < n && corridor[ind] != 'S') ind++, dis++;
    if (ind < n) {
      ans = (ans * dis) % MOD;
      pre = 0;
    }
  }
  return ans;
}

int main() {
  string corridor;
  cin >> corridor;
  cout << numberOfWays(corridor) << endl;
  return 0;
}
