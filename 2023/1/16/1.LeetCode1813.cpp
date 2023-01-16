/*************************************************************************
	> File Name: 1.LeetCode1813.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月16日 星期一 11时22分50秒
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

bool areSentencesSimilar(string sentence1, string sentence2) {
  vector<string> words1, words2;
  int ind = 0;
  while (sentence1[ind]) {
    string s = "";
    while (sentence1[ind] && sentence1[ind] != ' ')
      s += sentence1[ind++];
    if (sentence1[ind])
      ind++;
    words1.push_back(s);
  }
  ind = 0;
  while (sentence2[ind]) {
    string s = "";
    while (sentence2[ind] && sentence2[ind] != ' ')
      s += sentence2[ind++];
    if (sentence2[ind])
      ind++;
    words2.push_back(s);
  }
  int n = words1.size(), m = words2.size();
  int l = 0, r = 0;
  if (n >= m) {
    while (l < m && words1[l] == words2[l])
      l++;
    while (r < m && words1[n - 1 - r] == words2[m - 1 - r])
      r++;
    return l + r >= m;
  } 
  while (l < n && words1[l] == words2[l])
    l++;
  while (r < n && words1[n - 1 - r] == words2[m - 1 - r])
    r++;
  return l + r >= n;
}

int main() {
  return 0;
}
