/*************************************************************************
	> File Name: 2.LeetCode6187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月18日 星期日 09时28分05秒
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

long long minimumMoney(vector<vector<int>>& transactions) {
  long long neg = 0;
  for (auto && x : transactions)
    neg += min(0, x[1] - x[0]);
  long long ans = 0;
  for (auto && x : transactions) {
    int dis = x[1] - x[0];
    if (dis < 0)
      ans = max(ans, x[0] - (neg - dis));
    else
      ans = max(ans, x[0] - neg);
  }
  return ans;
}

int main() {
  return 0;
}
