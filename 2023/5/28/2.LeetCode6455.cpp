/*************************************************************************
	> File Name: 2.LeetCode6455.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月28日 星期日 10时49分54秒
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

long long calculate(string s, char pos, char neg) {
  long n = s.size();
  vector<long> left(n, INT64_MAX), right(n, INT64_MAX);
  for (long i = 0; i < n;) {
    if (s[i] == neg) {
      left[i] = i >= 1 ? left[i - 1] : 0;
      i++;
      continue;
    }
    long ind = i;
    while (ind < n && s[ind] == pos) {
      left[ind] = (i - 1 >= 0 ? left[i - 1] : 0) + ind + i + 1;
      ind++;
    }
    i = ind;
  }
  for (long i = n - 1; i >= 0;) {
    if (s[i] == neg) {
      right[i] = i < n - 1 ? right[i + 1] : 0;
      i--;
      continue;
    }
    long ind = i;
    while (ind >= 0 && s[ind] == pos) {
      right[ind] = (i + 1 < n ? right[i + 1] : 0) + n - ind + n - i - 1;
      ind--;
    }
    i = ind;
  }
  long ans = min(left[n - 1], right[0]);
  for (long i = 0; i < n - 1; i++)
    ans = min(ans, left[i] + right[i + 1]);
  return ans;
}

long long minimumCost(string s) {
  return min(calculate(s, '0', '1'), calculate(s, '1', '0'));
}

int main() {
  return 0;
}
