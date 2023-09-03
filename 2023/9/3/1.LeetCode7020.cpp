/*************************************************************************
	> File Name: 1.LeetCode7020.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月03日 星期日 10时30分56秒
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

int countSymmetricIntegers(int low, int high) {
  int ans = 0;
  for (int i = low; i <= high; i++) {
    string s = to_string(i);
    if (s.size() & 1)
      continue;
    int n = s.size();
    int pre = 0, suf = 0;
    for (int j = 0; j < n / 2; j++)
      pre += s[j] - '0';
    for (int j = n / 2; j < n; j++)
      suf += s[j] - '0';
    ans += pre == suf ? 1 : 0;
  }
  return ans;
}

int main() {
  return 0;
}
