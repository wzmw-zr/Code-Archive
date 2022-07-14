/*************************************************************************
	> File Name: 2.LeetCode745.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月14日 星期四 09时56分14秒
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

class WordFilter {
public:
  unordered_map<string, int> mp;

  WordFilter(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
      string pre = "";
      int n = words[i].size();
      for (int j = 0; j < n; j++) {
        pre += words[i][j];
        string suf = "";
        for (int k = n - 1; k >= 0; k--) {
          suf = words[i][k] + suf;
          string s = pre + " " + suf;
          mp[s] = i;
        }
      }
    }
  }

  int f(string pref, string suff) {
    string s = pref + " " + suff;
    if (mp.count(s)) return mp[s];
    return -1;
  }
};

int main() {
  return 0;
}
