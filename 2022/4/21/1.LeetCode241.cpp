/*************************************************************************
	> File Name: 1.LeetCode241.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月21日 星期四 10时40分23秒
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

int calculate(int x, int y, char c) {
  switch (c) {
    case '+' : return x + y;
    case '-' : return x - y;
    case '*' : return x * y;
  }
  return 0;
}

vector<int> diffWaysToCompute(string expression) {
  vector<int> nums;
  vector<char> ops;
  int ind = 0;
  while (expression[ind]) {
    if (expression[ind] >= '0' && expression[ind] <= '9') {
      string num = "";
      while (expression[ind] && expression[ind] >= '0' && expression[ind] <= '9') num += expression[ind++];
      nums.push_back(stoi(num));
    } else ops.push_back(expression[ind++]);
  }
  int n = nums.size();
  vector<int> dp[n][n];
  for (int i = 0; i < n; i++) dp[i][i].push_back(nums[i]);
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j + i - 1 < n; j++) {
      for (int k = j; k < j + i - 1; k++) {
        for (auto x : dp[j][k]) {
          for (auto y : dp[k + 1][j + i - 1]) {
            dp[j][j + i - 1].push_back(calculate(x, y, ops[k]));
          }
        }
      }
    }
  }
  return dp[0][n - 1];
}

int main() {
  string expression;
  cin >> expression;
  auto res = diffWaysToCompute(expression);
  for (int x : res) cout << x << " ";
  cout << endl;
  return 0;
}
