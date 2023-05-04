/*************************************************************************
	> File Name: 1.LeetCode2106.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月04日 星期四 09时36分59秒
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

int MAX_N = 2e5 + 10;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
  vector<int> pre(MAX_N + 10, 0);
  for (auto && fruit : fruits)
    pre[fruit[0] + 1] = fruit[1];
  for (int i = 1; i < MAX_N; i++)
    pre[i] += pre[i - 1];
  int ans = 0;
  for (int i = 0; i <= k / 2; i++) {
    int left = max(0, startPos - i);
    int right = min(startPos + (k - 2 * i), MAX_N);
    ans = max(ans, pre[right + 1] - pre[left]);

    left = max(0, startPos - (k - 2 * i));
    right = min(startPos + i, MAX_N);
    ans = max(ans, pre[right + 1] - pre[left]);
  }
  return ans;
}

int main() {
  return 0;
}
