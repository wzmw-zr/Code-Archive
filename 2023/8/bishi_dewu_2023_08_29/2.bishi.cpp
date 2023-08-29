/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月29日 星期二 10时21分40秒
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
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i <= n - x; i++) {
    string str = s.substr(i, x);
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    if (str == tmp) {
      ans = 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
