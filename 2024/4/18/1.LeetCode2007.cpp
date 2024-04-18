/*************************************************************************
	> File Name: 1.LeetCode2007.cpp
	> Author: 
	> Mail: 
	> Created Time: 2024年04月18日 星期四 10时40分56秒
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

vector<int> findOriginalArray(vector<int>& changed) {
  map<int, int> mp;
  for (int &x : changed)
    mp[x]++;
  set<int> st(changed.begin(), changed.end());
  vector<int> ans;
  for (auto && x : st) {
    if (x == 0) {
      if (mp[x] & 1)
        return {};
      for (int i = 0; i < mp[x] / 2; i++)
        ans.push_back(x);
      continue;
    }
    if (mp.count(x)) {
      if (mp.count(x * 2) < mp.count(x))
        return {};
      for (int i = 0; i < mp[x]; i++)
        ans.push_back(x);
      mp[x * 2] -= mp[x];
      if (mp[x * 2] == 0)
        mp.erase(x * 2);
      mp.erase(x);
    }
  }
  return ans;
}

int main() {
  vector<int> changed = {1};
  vector<int> ans = findOriginalArray(changed);
  for (auto && x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
