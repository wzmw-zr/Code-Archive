/*************************************************************************
	> File Name: 3.LeetCode1048.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月27日 星期四 14时39分10秒
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

int longestStrChain(vector<string>& words) {
  int n = words.size();
  sort(words.begin(), words.end(), [&](string &x, string &y){
    return x.size() < y.size();
  });
  unordered_map<string, int> mp;
  int ans = 0;
  for (auto && word : words) {
    mp[word] = 1;
    for (int i = 0; i < word.size(); i++) {
      string s = word.substr(0, i) + word.substr(i + 1);
      if (mp.count(s))
        mp[word] = max(mp[word], mp[s] + 1);
    }
    ans = max(ans, mp[word]);
  }
  return ans;
}

int main() {
  return 0;
}
