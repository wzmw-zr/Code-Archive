/*************************************************************************
	> File Name: 1.LeetCode954.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月01日 星期五 00时12分09秒
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

bool canReorderDoubled(vector<int>& arr) {
  map<int, int> mp;
  for (int x : arr) mp[x]++;
  for (auto iter = mp.begin(); iter != mp.end(); ) {
    int x = iter->first;
    if (x < 0) {
      if (x % 2 != 0) return false;
      if (!mp.count(x / 2) || mp[x] > mp[x / 2]) return false;
      mp[x / 2] -= mp[x];
      if (mp[x / 2] == 0) mp.erase(x / 2);
      iter = mp.erase(iter);
    } else if (x == 0) {
      if (mp[x] % 2 != 0) return false;
      iter = mp.erase(iter);
    } else {
      if (!mp.count(x * 2) || mp[x] > mp[x * 2])  return false;
      mp[x * 2] -= mp[x];
      if (mp[x * 2] == 0) mp.erase(x * 2);
      iter = mp.erase(iter);
    }
  }
  return mp.empty();
}

int main() {
  return 0;
}
