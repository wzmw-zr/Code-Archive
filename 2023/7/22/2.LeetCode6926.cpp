/*************************************************************************
	> File Name: 2.LeetCode6926.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月22日 星期六 22时40分31秒
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

string sortVowels(string s) {
  int n = s.size();
  string str = "";
  vector<int> inds;
  unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  for (int i = 0; i < n; i++) {
    if (st.count(s[i])) {
      str += s[i];
      inds.push_back(i);
    }
  }
  sort(str.begin(), str.end());
  for (int i = 0; i < inds.size(); i++)
    s[inds[i]] = str[i];
  return s;
}

int main() {
  return 0;
}
