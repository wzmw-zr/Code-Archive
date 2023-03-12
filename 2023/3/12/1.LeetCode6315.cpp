/*************************************************************************
	> File Name: 1.LeetCode6315.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月12日 星期日 10时31分03秒
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

int vowelStrings(vector<string>& words, int left, int right) {
  unordered_set<char> st({'a', 'e', 'i', 'o', 'u'});
  int ans = 0;
  for (int i = left; i <= right; i++) {
    if (st.count(words[i][0]) && st.count(*words[i].rbegin()))
      ans++;
  }
  return ans;
}

int main() {
  return 0;
}
