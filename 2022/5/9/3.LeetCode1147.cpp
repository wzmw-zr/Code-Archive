/*************************************************************************
	> File Name: 3.LeetCode1147.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月09日 星期一 21时16分36秒
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

long base = 233;
long MOD = 1e9 + 7;

int longestDecomposition(string text) {
  int cnt = 0;
  int l = 0, r = static_cast<int>(text.size()) - 1;
  while (l < r) {
    long val1 = 0, val2 = 0;
    long temp = 1;
    do {
      val1 = (val1 * base + (text[l] - 'a' + 1)) % MOD;
      val2 = (val2 + (text[r] - 'a' + 1) * temp) % MOD;
      temp = temp * base % MOD;
      l++, r--;
    } while (l < r && val1 != val2);
    if (val1 == val2) cnt += 2;
    else if (l > r) cnt += 1;
  }
  if (l == r) cnt += 1;
  return cnt;
}

int main() {
  string text;
  cin >> text;
  cout << longestDecomposition(text) << endl;
  return 0;
}
