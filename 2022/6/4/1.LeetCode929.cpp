/*************************************************************************
	> File Name: 1.LeetCode929.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月04日 星期六 09时09分09秒
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

int numUniqueEmails(vector<string>& emails) {
  unordered_set<string> st;
  auto convert = [](string &s) -> string {
    string prefix = "";
    string suffix = "";
    int ind = 0;
    for (int i = 0; s[i]; i++) {
      if (s[i] == '@') {
        ind = i;
        break;
      }
      prefix += s[i];
    }
    suffix = s.substr(ind);
    string t = "";
    for (char c : prefix) {
      if (c == '.') {
        continue;
      } else if (c == '+') {
        break;
      } else {
        t += c;
      }
    }
    return t + suffix;
  };
  for (string email : emails) 
    st.insert(convert(email));
  return st.size();
}

int main() {
  return 0;
}
