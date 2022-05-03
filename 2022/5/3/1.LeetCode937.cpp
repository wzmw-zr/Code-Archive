/*************************************************************************
	> File Name: 1.LeetCode937.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月03日 星期二 10时44分35秒
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

#define LETTER 0
#define DIGIT 1

struct Log {
  int type;
  string identifier;
  string content;

  Log() = default;
  Log(string &log) {
    int ind = 0;
    while (log[ind] && log[ind] != ' ') identifier += log[ind++];
    ind++;
    content = log.substr(ind);
    type = (content[0] >= '0' && content[0] <= '9') ? DIGIT : LETTER;
  }

  bool operator<(const struct Log &that) const {
    return this->content == that.content ? this->identifier < that.identifier : this->content < that.content;
  }

  string to_string() {
    return this->identifier + " " + this->content;
  }
};

vector<string> reorderLogFiles(vector<string>& logs) {
  vector<Log> letter_logs;
  vector<Log> digit_logs;
  for (string &log : logs) {
    struct Log temp(log);
    if (temp.type == LETTER) letter_logs.push_back(temp);
    else digit_logs.push_back(temp);
  }
  sort(letter_logs.begin(), letter_logs.end());
  vector<string> ans;
  for (auto && log : letter_logs) ans.push_back(log.to_string());
  for (auto && log : digit_logs) ans.push_back(log.to_string());
  return ans;
}

int main() {
  return 0;
}
