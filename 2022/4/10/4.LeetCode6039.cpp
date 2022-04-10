/*************************************************************************
	> File Name: 4.LeetCode6039.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月10日 星期日 11时57分43秒
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

long long MOD = 1e9 + 7;

int maximumProduct(vector<int>& nums, int k) {
  priority_queue<long, vector<long>, greater<long>> que;
  for (int x : nums) que.push(x);
  while (k) {
    long t = que.top();
    que.pop();
    que.push(t + 1);
    k--;
  }
  long long ans = 1;
  while (!que.empty()) {
    long long t = que.top();
    que.pop();
    ans = (ans * t) % MOD;
  }
  return ans;
}

int main() {
  return 0;
}
