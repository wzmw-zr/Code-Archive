/*************************************************************************
	> File Name: 1.LeetCode1455.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月21日 星期日 08时56分00秒
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

int isPrefixOfWord(string sentence, string searchWord) {
  int ind = 0;
  vector<string> words;
  while (sentence[ind]) {
    string word = "";
    while (sentence[ind] && sentence[ind] != ' ')
      word += sentence[ind++];
    if (sentence[ind]) 
      ind++;
    words.push_back(word);
  }
  for (int i = 0; i < words.size(); i++) {
    if (words[i].size() < searchWord.size())
      continue;
    if (words[i].substr(0, static_cast<int>(searchWord.size())) == searchWord) 
      return i + 1;
  }
  return -1;
}

int main() {
  return 0;
}
