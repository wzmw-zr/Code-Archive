/*************************************************************************
	> File Name: 1.LeetCode433.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月07日 星期六 09时12分14秒
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

using PSI = pair<string, int>;

int minMutation(string start, string end, vector<string>& bank) {
  queue<PSI> que;
  unordered_map<string, int> mp;
  unordered_set<string> st;
  st.insert(start);
  for (auto && s : bank) st.insert(s);
  que.push(PSI(start, 0));
  vector<char> chs = {'A', 'C', 'G', 'T'};
  while (!que.empty()) {
    auto temp = que.front();
    if (temp.first == end) return temp.second;
    que.pop();
    if (mp.count(temp.first)) continue;
    mp[temp.first] = temp.second;
    string str = temp.first;
    for (int i = 0; i < 8; i++) {
      char c = str[i];
      for (char ch : chs) {
        if (ch == c) continue;
        str[i] = ch;
        if (mp.count(str)) continue;
        if (!st.count(str)) continue;
        que.push(PSI(str, temp.second + 1));
      }
      str[i] = c;
    }
  }
  return -1;
}

int main() {
  return 0;
}
