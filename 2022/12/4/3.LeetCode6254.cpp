/*************************************************************************
	> File Name: 3.LeetCode6254.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月04日 星期日 10时40分03秒
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

long long dividePlayers(vector<int>& skill) {
  long long n = skill.size();
  long long sum = 0;
  for (int x : skill)
    sum += x;
  if ((sum * 2) % n)
    return -1;
  long val = sum * 2 / n;
  map<long, long> mp;
  for (int x : skill)
    mp[x]++;
  long long ans = 0;
  while (!mp.empty()) {
    long x = mp.begin()->first;
    long y = val - x;
    if (x != y) {
      if (!mp.count(y))
        return -1;
      ans += x * y;
      if (!(--mp[x]))
        mp.erase(x);
      if (!(--mp[y]))
        mp.erase(y);
    } else if (x == y) {
      if (mp[x] < 2)
        return -1;
      ans += x * x;
      mp[x] -= 2;
      if (!mp[x])
        mp.erase(x);
    }
  }
  return ans;
}

int main() {
  return 0;
}
