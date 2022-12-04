/*************************************************************************
	> File Name: 2.LeetCoe6253.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月04日 星期日 10时33分34秒
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

bool isCircularSentence(string s) {
  vector<string> words;
  int ind = 0;
  while (s[ind]) {
    string word = "";
    while (s[ind] && s[ind] != ' ')
      word += s[ind++];
    if (s[ind] == ' ')
      ind++;
    if (word != "")
      words.push_back(word);
  }
  words.push_back(words[0]);
  int n = words.size();
  for (int i = 0; i < n - 1; i++) {
    if (*words[i].rbegin() != *words[i + 1].begin())
      return false;
  }
  return true;
}

int main() {
  return 0;
}
