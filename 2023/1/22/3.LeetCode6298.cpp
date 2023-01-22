/*************************************************************************
	> File Name: 3.LeetCode6298.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月22日 星期日 10时45分55秒
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

using PII = pair<int, int>;

bool makeStringsEqual(string s, string target) {
  int n = s.size();
  map<PII, int> mp;
  for (int i = 0; i < n; i++)
    mp[PII(s[i] - '0', target[i] - '0')]++;
  if (mp.count(PII(0, 1))) {
    if (!(mp.count(PII(1, 1)) || mp.count(PII(1, 0))))
      return false;
    mp[PII(1, 1)] += mp[PII(0, 1)];
    mp.erase(PII(0, 1));
  }
  if (mp.count(PII(1, 0))) {
    if (!mp.count(PII(1, 1)))
      return false;
  }
  return true;
}

int main() {
  return 0;
}
