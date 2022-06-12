/*************************************************************************
	> File Name: 1.LeetCode890.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月12日 星期日 09时05分18秒
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

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
  unordered_map<string, vector<string>> match;
  auto encode = [](string &s) -> string {
    char ch = 'a';
    unordered_map<char, char> mp;
    string ans = "";
    for (char c : s) {
      if (!mp.count(c)) mp[c] = ch++;
      ans += mp[c];
    }
    return ans;
  };
  for (auto word : words) {
    string t = encode(word);
    if (!match.count(t)) match[t] = vector<string>();
    match[t].push_back(word);
  }
  return match[encode(pattern)];
}

int main() {
  return 0;
}
