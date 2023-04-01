/*************************************************************************
	> File Name: 1.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 10时02分32秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PLC = pair<long, char>;

vector<double> calculate(vector<long> &nums, vector<PLC> &ops) {
  long sum = 0;
  for (int x : nums)
    sum += x;
  vector<double> ans;
  for (auto && [ind, op] : ops) {
    double t = sum;
    t = t - nums[ind - 1] - nums[ind];
    if (op == '+') {
      t = t + nums[ind - 1] + nums[ind];
    } else if (op == '-') {
      t = t + nums[ind - 1] - nums[ind];
    } else if (op == '*') {
      t = t + nums[ind - 1] * nums[ind];
    } else {
      t = t + 1.0 * nums[ind - 1] / nums[ind];
    }
    ans.push_back(t);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<long> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int m;
  cin >> m;
  vector<PLC> ops;
  for (int i = 0; i < m; i++) {
    long ind;
    char c;
    cin >> ind >> c;
    ops.push_back(PLC(ind, c));
  }
  vector<double> ans = calculate(nums, ops);
  for (int i = 0; i < ans.size(); i++) {
    if (i != 0)
      printf(" ");
    printf("%.1f", ans[i]);
  }
  printf("\n");
  return 0;
}
