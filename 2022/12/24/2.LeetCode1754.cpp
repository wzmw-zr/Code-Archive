/*************************************************************************
	> File Name: 2.LeetCode1754.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月24日 星期六 09时42分38秒
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

string largestMerge(string word1, string word2) {
  int n = word1.size(), m = word2.size();
  int ind_1 = 0, ind_2 = 0;
  string ans = "";
  while (ind_1 < n || ind_2 < m) {
    if (ind_1 < n && (ind_2 == m || word1[ind_1] >= word2[ind_2])) {
      if (ind_2 == m) {
        ans += word1[ind_1++];
      } else if (word1[ind_1] == word2[ind_2]) {
        string s1 = word1.substr(ind_1), s2 = word2.substr(ind_2);
        if (s1 >= s2)
          ans += word1[ind_1++];
        else
          ans += word2[ind_2++];
      } else {
        ans += word1[ind_1++];
      }
    } else {
      ans += word2[ind_2++];
    }
  }
  return ans;
}

int main() {
  return 0;
}
