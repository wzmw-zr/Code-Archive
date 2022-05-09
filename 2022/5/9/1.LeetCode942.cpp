/*************************************************************************
	> File Name: 1.LeetCode942.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月09日 星期一 08时28分20秒
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

vector<int> diStringMatch(string s) {
  int n = s.size();
  int l = 0, r = n;
  unordered_set<int> st;
  for (int i = 0; i <= n; i++) st.insert(i);
  vector<int> ans;
  for (char c : s) {
    if (c == 'I') {
      st.erase(l);
      ans.push_back(l++);
    } else {
      st.erase(r);
      ans.push_back(r--);
    }
  }
  ans.push_back(*st.begin());
  return ans;
}

int main() {
  return 0;
}
