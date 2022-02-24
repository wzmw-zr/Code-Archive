/*************************************************************************
	> File Name: 2.LeetCode30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月24日 星期四 18时26分50秒
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

vector<int> findSubstring(string s, vector<string>& words) {
  int n = s.size(), m = words[0].size(), len = words.size();
  unordered_map<string, int> cnts;
  unordered_map<string, int> mp;
  map<int, int> state;
  vector<int> ids(n, -1);

  for (auto &&word : words) cnts[word]++;
  int id = 0;
  for (auto &&[word, cnt] : cnts) mp[word] = id++;
  for (auto &&[word, w_id] : mp) state[w_id] = cnts[word];
  for (int i = 0; i <= n - m; i++) {
    string temp = s.substr(i, m);
    if (mp.count(temp)) ids[i] = mp[temp];
  }
  vector<int> ans;

  for (int i = 0; i < m; i++) {
    map<int, int> temp;
    int l = i, r = i;
    while (r < n) {
      if (ids[r] == -1) {
        r += m;
        l = r;
        temp.clear();
        continue;
      }
      temp[ids[r]]++;
      if (((r - l) / m + 1) == len) {
        if (temp == state) ans.push_back(l);
        if (!(--temp[ids[l]])) temp.erase(ids[l]);
        l += m;
        r += m;
      } else r += m;
    }
  }
  return ans;
}

int main() {
  return 0;
}
