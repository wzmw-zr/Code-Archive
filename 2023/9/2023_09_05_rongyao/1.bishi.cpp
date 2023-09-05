/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月05日 星期二 19时22分20秒
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
  string s;
  getline(cin, s);
  int ind = 0;
  int ans = 0;
  int flag = 1;
  while (s[ind]) {
    string num;
    while (s[ind] && (s[ind] >= '0' && s[ind] <= '9'))
      num += s[ind++];
    ans += stoi(num) * flag;
    if (s[ind])
      flag = s[ind++] == '+' ? 1 : -1;
  }
  cout << ans << endl;
  return 0;
}
