/*************************************************************************
	> File Name: 2.LeetCode6075.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月22日 星期日 10时38分16秒
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

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
  int n = capacity.size();
  priority_queue<PII, vector<PII>, greater<PII>> que;
  for (int i = 0; i < n; i++) 
    que.push(PII(capacity[i] - rocks[i], i));
  int cnt = 0;
  while (!que.empty() && additionalRocks) {
    auto temp = que.top();
    que.pop();
    if (temp.first <= additionalRocks) {
      cnt++;
      additionalRocks -= temp.first;
    } else break;
  }
  return cnt;
}

int main() {
  return 0;
}
