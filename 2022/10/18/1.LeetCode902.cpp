/*************************************************************************
	> File Name: 1.LeetCode902.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月18日 星期二 09时25分09秒
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

int pow(int x, int y) {
  int ans = 1;
  for (int i = 0; i < y; i++)
    ans *= x;
  return ans;
}

int dfs(vector<string> &digits, string str) {
  if (str.size() == 0 || str[0] == '0')
    return 0;
  if (str.size() == 1) {
    int ans = 0;
    for (string &s : digits) {
      if (s <= str)
        ans++;
    }
    return ans;
  }
  int m = digits.size();
  int len = str.size();
  int top = stoi(str.substr(0, 1));
  if (len == 1 && top < stoi(digits[0])) 
    return 0;
  int ind = -1;
  for (int i = 0; i < m; i++) {
    if (stoi(digits[i]) <= top)
      ind = i;
  }
  if (ind == -1)
    return 0;
  if (stoi(digits[ind]) == top)
    return ind * pow(m, len - 1) + dfs(digits, str.substr(1));
  return (ind + 1) * pow(m, len - 1);
}

int atMostNGivenDigitSet(vector<string>& digits, int n) {
  int m = digits.size();
  string str = to_string(n);
  int len = str.size();
  int ans = 0;
  for (int i = 1; i < len; i++) 
    ans += pow(m, i);
  ans += dfs(digits, str);
  return ans;
}

int main() {
  return 0;
}
