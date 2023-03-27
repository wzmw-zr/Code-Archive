/*************************************************************************
	> File Name: 1.LeetCode1638.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月27日 星期一 09时38分44秒
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

int countSubstrings(string s, string t) {
  int n = s.size(), m = t.size();
  int ans = 0;
  for (int l = 1; l <= min(n, m); l++) {
    unordered_map<string, int> mp;
    for (int i = 0; i <= m - l; i++)
      mp[t.substr(i, l)]++;
    for (int i = 0; i <= n - l; i++) {
      string str = s.substr(i, l);
      int x = str.size();
      for (int j = 0; j < x; j++) {
        char c = str[j];
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (ch == c)
            continue;
          str[j] = ch;
          if (mp.count(str))
            ans += mp[str];
        }
        str[j] = c;
      }
    }
  }
  return ans;
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << countSubstrings(s, t) << endl;
  return 0;
}
