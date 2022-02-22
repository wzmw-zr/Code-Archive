/*************************************************************************
	> File Name: 1.LeetCode917.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月23日 星期三 00时03分06秒
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

bool is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string reverseOnlyLetters(string s) {
  int n = s.size();
  int l = 0, r = n - 1;
  while (l < r) {
    while (l < n && !is_letter(s[l])) l++;
    while (r >= 0 && !is_letter(s[r])) r--;
    if (l >= r) break;
    swap(s[l], s[r]);
    l++, r--;
  }
  return s;
}

int main() {
  string s;
  cin >> s;
  cout << reverseOnlyLetters(s) << endl;
  return 0;
}
