/*************************************************************************
	> File Name: 1.LeetCode1601.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月28日 星期一 00时05分34秒
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

int maximumRequests(int n, vector<vector<int>>& requests) {
  int m = requests.size();
  int ans = 0;
  for (int i = 0; i < (1 << m); i++) {
    vector<int> in(n, 0);
    vector<int> out(n, 0);
    for (int j = 0; j < m; j++) {
      if ((i & (1 << j)) == 0) continue;
      out[requests[j][0]]++;
      in[requests[j][1]]++;
    }
    int flag = 1;
    for (int j = 0; j < n; j++) {
      if (out[j] == in[j]) continue;
      flag = 0;
      break;
    }
    if (flag) ans = max(ans, __builtin_popcount(i));
  }
  return ans;
}

int main() {
  return 0;
}
