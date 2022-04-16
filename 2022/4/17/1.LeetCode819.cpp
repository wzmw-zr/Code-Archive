/*************************************************************************
	> File Name: 1.LeetCode819.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月17日 星期日 00时22分16秒
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

string mostCommonWord(string paragraph, vector<string>& banned) {
  unordered_map<string, int> mp;
  auto is_char = [](char c) -> bool {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  };
  for (int i = 0; paragraph[i]; ) {
    if (!is_char(paragraph[i])) {
      i++;
      continue;
    }
    string s = "";
    while (paragraph[i] && is_char(paragraph[i])) {
      if (paragraph[i] >= 'a' && paragraph[i] <= 'z') s += paragraph[i];
      else s += paragraph[i] + 32;
      i++;
    }
    mp[s]++;
  }
  for (string &s : banned) mp.erase(s);
  string ans;
  int cnt = 0;
  for (auto &&[word, num] : mp) {
    if (num > cnt) {
      ans = word;
      cnt = num;
    }
  }
  return ans;
}

int main() {
  return 0;
}
