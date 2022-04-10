/*************************************************************************
	> File Name: 3.LeetCode6038.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月10日 星期日 11时04分40秒
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

string minimizeResult(string expression) {
  string left = "", right = "";
  for (int i = 0, flag = 0; expression[i]; i++) {
    if (expression[i] == '+') {
      flag = 1;
      continue;
    }
    if (!flag) left += expression[i];
    else right += expression[i];
  }
  int mmin = INT32_MAX;
  int p = 0, q = 1;
  for (int i = 0; i < left.size(); i++) {
    for (int j = 1; j <= right.size(); j++) {
      string left_1 = left.substr(0, i);
      string left_2 = left.substr(i);
      string right_1 = right.substr(0, j);
      string right_2 = right.substr(j);
      int l1 = left_1.size() == 0 ? 1 : stoi(left_1);
      int l2 = stoi(left_2);
      int r1 = stoi(right_1);
      int r2 = right_2.size() == 0 ? 1 : stoi(right_2);
      int val = l1 * (l2 + r1) * r2;
      if (val < mmin) {
        mmin = val;
        p = i;
        q = j;
      }
    }
  }
  string ans = "";
  for (int i = 0; i < p; i++) ans += left[i];
  ans += "(";
  for (int i = p; i < left.size(); i++) ans += left[i];
  ans += "+";
  for (int i = 0; i < q; i++) ans += right[i];
  ans += ")";
  for (int i = q; i < right.size(); i++) ans += right[i];
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << minimizeResult(s) << endl;
  return 0;
}
