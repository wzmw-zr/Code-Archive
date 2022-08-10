/*************************************************************************
	> File Name: 1.LeetCode640.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月10日 星期三 09时13分16秒
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

vector<int> parse(string s) {
  int param = 0, num = 0;
  int ind = 0;
  while (s[ind]) {
    int flag = 1;
    if (s[ind] == '+' || s[ind] == '-') {
      flag = s[ind] == '+' ? 1 : -1;
      ind++;
    }
    string str = "";
    while (s[ind] && s[ind] != '+' && s[ind] != '-')
      str += s[ind++];
    if (*str.rbegin() == 'x') {
      int n = str.size();
      int coefficient = n == 1 ? 1 : stoi(str.substr(0, n - 1));
      param += flag * coefficient;
    } else {
      num += flag * stoi(str);
    }
  }
  return vector<int>({param, num});
}

string solveEquation(string equation) {
  int ind = 0;
  while (equation[ind] != '=') ind++;
  string left = equation.substr(0, ind);
  string right = equation.substr(ind + 1);
  vector<int> lval = parse(left);
  vector<int> rval = parse(right);
  if (lval[0] == rval[0] && lval[1] == rval[1])
    return "Infinite solutions";
  if (lval[0] == rval[0])
    return "No solution";
  int val = (rval[1] - lval[1]) / (lval[0] - rval[0]);
  return "x=" + to_string(val);
}

int main() {
  string equation;
  cin >> equation;
  cout << solveEquation(equation) << endl;
  return 0;
}
