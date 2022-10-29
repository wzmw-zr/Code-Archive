/*************************************************************************
	> File Name: 2.LeetCode6225.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月29日 星期六 22时32分38秒
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

vector<int> calculcate(string &s) {
  int n = s.size();
  vector<int> ans;
  for (int i = 0; i < n - 1; i++)
    ans.push_back(int(s[i + 1] - s[i]));
  return ans;
}

string oddString(vector<string>& words) {
  int n = words.size();
  map<vector<int>, vector<string>> mp;
  for (int i = 0; i < n; i++) {
    vector<int> diff = calculcate(words[i]);
    if (!mp.count(diff))
      mp[diff] = vector<string>(0);
    mp[diff].push_back(words[i]);
  }
  if (mp.begin()->second.size() == 1)
    return mp.begin()->second[0];
  return mp.rbegin()->second[0];
}

int main() {
  return 0;
}
