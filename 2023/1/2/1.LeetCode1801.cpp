/*************************************************************************
	> File Name: 1.LeetCode1801.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月02日 星期一 09时40分44秒
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

using PII = pair<int, int>;

long MOD = 1e9 + 7;
int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
  priority_queue<PII, vector<PII>, greater<PII>> sell;
  priority_queue<PII, vector<PII>, less<PII>> buy;
  for (auto && order : orders) {
    int price = order[0], amount = order[1], type = order[2];
    if (type == 0) {
      while (!sell.empty() && amount && price >= sell.top().first) {
        auto temp = sell.top();
        sell.pop();
        if (temp.second <= amount) {
          amount -= temp.second;
        } else {
          temp.second -= amount;
          amount = 0;
          sell.push(temp);
        }
      }
      if (amount)
        buy.push({price, amount});
    } else {
      while (!buy.empty() && amount && price <= buy.top().first) {
        auto temp = buy.top();
        buy.pop();
        if (temp.second <= amount) {
          amount -= temp.second;
        } else {
          temp.second -= amount;
          amount = 0;
          buy.push(temp);
        }
      }
      if (amount)
        sell.push({price, amount});
    }
  }
  long ans = 0;
  while (!sell.empty()) {
    ans = (ans + sell.top().second) % MOD;
    sell.pop();
  }
  while (!buy.empty()) {
    ans = (ans + buy.top().second) % MOD;
    buy.pop();
  }
  return ans;
}

int main() {
  return 0;
}
