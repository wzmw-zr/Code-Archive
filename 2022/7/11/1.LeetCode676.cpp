/*************************************************************************
	> File Name: 1.LeetCode676.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月11日 星期一 09时15分22秒
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

class MagicDictionary {
public:
  vector<string> _dictionary;

  MagicDictionary() {}

  void buildDict(vector<string> dictionary) {
    for (auto && s : dictionary) _dictionary.push_back(s);
  }

  bool search(string searchWord) {
    int n = searchWord.size();
    for (auto && s : _dictionary) {
      if (s.size() != n) continue;
      int diff = 0;
      for (int i = 0; i < n; i++) diff += (s[i] == searchWord[i] ? 0 : 1);
      if (diff == 1) return true;
    }
    return false;
  }
};

int main() {
  return 0;
}
