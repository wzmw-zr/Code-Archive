/*************************************************************************
	> File Name: 1.LeetCode388.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月20日 星期三 08时49分27秒
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

using PIS = pair<int, string>;

int lengthLongestPath(string input) {
  int l = 0, r = 0;
  int ans = 0;
  vector<PIS> path;
  auto contain_dot = [](string &name) -> bool {
    for (char c : name) {
      if (c == '.') return true;
    }
    return false;
  };
  while (input[r]) {
    int level = 0;
    while (input[r] && input[r] == '\t') level++, r++;
    l = r;
    while (input[r] && input[r] != '\n') r++;
    string temp = input.substr(l, r - l);
    while (path.size()) {
      auto iter = prev(path.end());
      if ((*iter).first >= level) path.pop_back();
      else break;
    }
    path.push_back(PIS(level, temp));
    if (contain_dot(temp)) {
      int len = 0;
      for (auto &&[depth, name] : path) len += name.size();
      len += path.size() - 1;
      ans = max(ans, len);
    }
    if (input[r]) r++;
  }
  return ans;
}

int main() {
  string input;
  cin >> input;
  cout << input << endl;
  cout << lengthLongestPath(input) << endl;
  return 0;
}
