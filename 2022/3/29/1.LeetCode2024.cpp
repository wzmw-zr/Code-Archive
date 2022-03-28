/*************************************************************************
	> File Name: 1.LeetCode2024.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月29日 星期二 00时17分51秒
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

int maxConsecutive(string &s, int k, char c) {
  int l = 0, r = 0, n = s.size();
  int cnt = 0;
  int ans = 0;
  while (r < n) {
    while (cnt <= k && r < n) {
      if (s[r] != c) cnt++;
      r++;
    }
    if (cnt > k) ans = max(ans, r - l - 1);
    else {
      ans = max(ans, r - l); 
      break;
    }
    while (cnt > k && l < r) {
      if (s[l] != c) cnt--;
      l++;
    }
  }
  return ans;
}

int maxConsecutiveAnswers(string answerKey, int k) {
  return max(maxConsecutive(answerKey, k, 'T'), maxConsecutive(answerKey, k, 'F'));
}

int main() {
  string answerKey;
  int k;
  cin >> answerKey >> k;
  cout << maxConsecutiveAnswers(answerKey, k) << endl;
  return 0;
}
