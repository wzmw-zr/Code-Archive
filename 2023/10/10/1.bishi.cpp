/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月10日 星期二 19时31分12秒
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
  int n, m, k;
  cin >> n >> m >> k;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int b, a;
    cin >> b >> a;
    if (!mp.count(b))
      mp[b] = a;
    mp[b] = min(mp[b], a);
  }
  long sum = 0;
  for (auto && [x, cnt] : mp)
    sum += cnt;
  cout << sum << endl;
  return 0;
}
