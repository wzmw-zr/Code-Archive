/*************************************************************************
	> File Name: 3.LeetCode6048.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月28日 星期六 22时36分59秒
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

string largestWordCount(vector<string>& messages, vector<string>& senders) {
  int n = messages.size();
  unordered_map<string, int> mp;
  auto count_word = [](string &s) -> int {
    int cnt = 0;
    int ind = 0;
    while (s[ind]) {
      while (s[ind] && s[ind] != ' ') ind++;
      cnt++;
      while (s[ind] && s[ind] == ' ') ind++;
    }
    return cnt;
  };
  for (int i = 0; i < n; i++) {
    mp[senders[i]] += count_word(messages[i]);
  }
  vector<PIS> arr;
  for (auto &&[name, cnt] : mp) arr.push_back(PIS(cnt, name));
  sort(arr.begin(), arr.end());
  return (*(arr.rbegin())).second;
}

int main() {
  return 0;
}
