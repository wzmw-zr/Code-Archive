/*************************************************************************
	> File Name: 1.LeetCode953.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月17日 星期二 09时26分26秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool isAlienSorted(vector<string>& words, string order) {
  unordered_map<char, char> mp;
  for (int i = 0; i < 26; i++) mp[order[i]] = 'a' + i;
  int n = words.size();
  auto change = [&](string &s) {
    for (int i = 0; s[i]; i++) s[i] = mp[s[i]];
  };
  for (int i = 0; i < n; i++) change(words[i]);
  vector<string> temp = words;
  sort(temp.begin(), temp.end());
  return words == temp;
}

int main() {
  return 0;
}
