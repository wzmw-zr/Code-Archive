/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月23日 星期六 14时07分53秒
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


int main() {
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++)
    cin >> strs[i];
  unordered_map<string, long> mp;
  for (int i = 0; i < n; i++) {
    sort(strs[i].begin(), strs[i].end());
    mp[strs[i]]++;
  }
  long ans = 0;
  for (auto && [s, cnt] : mp) 
    ans += cnt * (cnt - 1) / 2;
  cout << ans << endl;
  return 0;
}
