/*************************************************************************
	> File Name: 1.LeetCode720.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月17日 星期四 00时02分09秒
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

string longestWord(vector<string>& words) {
  unordered_set<string> st(words.begin(), words.end());
  string ans = "";
  queue<string> que;
  for (auto word : words) {
    if (word.size() == 1) que.push(word);
  }
  while (!que.empty()) {
    string temp = que.front();
    que.pop();
    if (temp.size() == ans.size()) ans = min(ans, temp);
    if (temp.size() > ans.size()) ans = temp;
    for (char c = 'a'; c <= 'z'; c++) {
      string str = temp + c;
      if (st.count(str)) que.push(str);
    }
  }
  return ans;
}

int main() {
  return 0;
}
