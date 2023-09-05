/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月05日 星期二 19时36分10秒
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

int check(string &s, int i) {
  string year = s.substr(i, 4);
  for (char c : year) {
    if (c >= '0' && c <= '9')
      continue;
    return 0;
  }
  if (s[i + 4] != '-')
    return 0;
  string month = s.substr(i + 5, 2);
  for (char c : month) {
    if (c >= '0' && c <= '9')
      continue;
    return 0;
  }
  if (s[i + 7] != '-')
    return 0;
  string day = s.substr(i + 8, 2);
  for (char c : day) {
    if (c >= '0' && c <= '9')
      continue;
    return 0;
  }
  if (s[i + 10] != 'T')
    return 0;
  string hour = s.substr(i + 11, 2);
  for (char c : hour) {
    if (c >= '0' && c <= '9')
      continue;
    return 0;
  }
  if (s[i + 13] != ':')
    return 0;
  string minute = s.substr(i + 14, 2);
  for (char c : minute) {
    if (c >= '0' && c <= '9')
      continue;
    return 0;
  }
  if (s[i + 16] != ':')
    return 0;
  string second = s.substr(i + 17, 2);
  for (char c : second) {
    if (c >= '0' && c <= '9')
      continue;
    return 0;
  }
  return 1;
}

struct Node {
  string s;
  vector<int> dates;
  int year, month, day, hour, minute, second;

  Node() = default;
  Node(string s) : s(s) {
    for (int i = 0; i <= s.size() - 19; i++) {
      if (check(s, i)) {
        year = stoi(s.substr(i, 4));
        month = stoi(s.substr(i + 5, 2));
        day = stoi(s.substr(i + 8, 2));
        hour = stoi(s.substr(i + 11, 2));
        minute = stoi(s.substr(i + 14, 2));
        second = stoi(s.substr(i + 17, 2));
        dates = vector<int>({year, month, day, hour, minute, second});
        break;
      }
    }
  }

  bool operator<(const struct Node &that) const {
    if (this->dates == that.dates) {
      return this->s.size() == that.s.size() ? this->s < that.s : this->s.size() < that.s.size();
    }
    return this->dates < that.dates;
  }
};

int main() {
  int n;
  cin >> n;
  unordered_set<string> st;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    st.insert(s);
  }
  vector<Node> nodes;
  for (auto &s : st)
    nodes.push_back(Node(s));
  sort(nodes.begin(), nodes.end());
  for (auto && node : nodes) {
    cout << node.s << endl;
  }
  return 0;
}
