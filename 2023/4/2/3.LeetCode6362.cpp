/*************************************************************************
	> File Name: 3.LeetCode6362.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 10时30分46秒
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

int findTheLongestBalancedSubstring(string s) {
  int ans = 0;
  int n = s.size();
  for (int l = 2; l <= n; l += 2) {
    for (int i = 0; i + l <= n; i++) {
      int flag = 0;

      for (int j = i; j < i + l / 2; j++) {
        if (s[j] == '0')
          continue;
        flag = 1;
        break;
      }
      if (flag)
        continue;

      for (int j = i + l / 2; j < i + l; j++) {
        if (s[j] == '1')
          continue;
        flag = 1;
        break;
      }
      if (flag)
        continue;
      ans = l;
    }
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << findTheLongestBalancedSubstring(s) << endl;
  return 0;
}
