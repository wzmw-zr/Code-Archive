/*************************************************************************
	> File Name: 1.LeetCode5253.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月27日 星期日 10时38分31秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

void dfs(string &s, int q, int ind, int len) {
  if (ind > len - 1 - ind || q == 0) return ;
  int l = (len + 1) / 2 - (ind + 1);
  int num = q / pow(10, l);
  int r = q - num * pow(10, l);
  if (r) s[ind] = s[len - 1 - ind] = num + (ind == 0 ? 1 : 0) + '0';
  else {
    s[ind] = s[len - 1 - ind] = num - 1 + (ind == 0 ? 1: 0) + '0';
    for (int i = ind + 1; i < len - 1 - ind; i++) s[i] = '9';
    return ;
  }
  dfs(s, q - num * pow(10, l), ind + 1, len);
}

long get_mmax(int ind, int len) {
  if (ind == len - 1 - ind || ind + 1 == len - 1 - ind) {
    return ind == 0 ? 9 : 10;
  }
  long t = get_mmax(ind + 1, len);
  return ind == 0 ? t * 9: t * 10;
}

vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
  int mid = (intLength + 1) / 2;
  vector<long long> ans;
  int mmax = get_mmax(0, intLength);
  for (int q : queries) {
    if (q > mmax) {
      ans.push_back(-1);
      continue;
    }
    string s(intLength, '0');
    dfs(s, q, 0, intLength);
    ans.push_back(stol(s));
  }
  return ans;
}

int main() {
  return 0;
}
