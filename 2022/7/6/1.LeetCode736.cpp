/*************************************************************************
	> File Name: 1.LeetCode736.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月06日 星期三 08时56分42秒
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

unordered_map<string, vector<int>> mp;

vector<string> ops = {"let", "add", "mult"};

bool is_variable(string &s) {
  for (char c : s) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
  }
  return false;
}

int evaluate(string expression) {
  int flag = 0;
  for (string & s : ops) {
    if (expression.find(s) != std::string::npos) {
      flag = 1;
      break;
    }
  }
  if (!flag) {
    if (is_variable(expression)) return *(mp[expression].rbegin());
    return stoi(expression);
  }
  vector<string> splits;
  int n = expression.size();
  int ind = 1;
  while (ind < n - 1) {
    string temp = "";
    if (expression[ind] != '(') {
      while (ind < n - 1 && expression[ind] != ' ') temp += expression[ind++];
    } else {
      int cnt = 0;
      do {
        if (expression[ind] == '(') cnt++;
        if (expression[ind] == ')') cnt--;
        temp += expression[ind];
        ind++;
      } while (cnt);
    }
    ind++;
    splits.push_back(temp);
  }
  string op = splits[0];

  if (op == "let") {
    int m = splits.size();
    unordered_map<string, int> local_mp;
    for (int i = 1; i < m - 1; i += 2) {
      if (!local_mp.count(splits[i])) {
        local_mp[splits[i]] = evaluate(splits[i + 1]);
        if (!mp.count(splits[i])) 
          mp[splits[i]] = vector<int>(0);
        mp[splits[i]].push_back(local_mp[splits[i]]);
      } else {
        local_mp[splits[i]] = evaluate(splits[i + 1]);
        mp[splits[i]].pop_back();
        mp[splits[i]].push_back(local_mp[splits[i]]);
      }
    }
    int ret = evaluate(splits[m - 1]);
    for (auto && [variable, value] : local_mp) {
      mp[variable].pop_back();
      if (mp[variable].size() == 0) mp.erase(variable);
    }
    return ret;
  } else if (op == "add") {
    int left = evaluate(splits[1]);
    int right = evaluate(splits[2]);
    return left + right;
  } else if (op == "mult") {
    int left = evaluate(splits[1]);
    int right = evaluate(splits[2]);
    return left * right;
  }
  return -1;
}

int main() {
  string expression;
  getline(cin, expression);
  cout << evaluate(expression) << endl;
  return 0;
}
