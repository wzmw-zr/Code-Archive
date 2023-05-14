/*************************************************************************
	> File Name: 1.LeetCode1054.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月14日 星期日 10时08分17秒
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

using PII = pair<int, int>;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
  unordered_map<int, int> mp;
  for (int x : barcodes)
    mp[x]++;
  priority_queue<PII> que;
  for (auto && [x, cnt] : mp)
    que.push(PII(cnt, x));
  vector<int> ans;
  while (!que.empty()) {
    auto node = que.top();
    que.pop();
    while (!que.empty() && que.top().first < node.first) {
      auto tmp = que.top();
      que.pop();
      ans.push_back(node.second);
      ans.push_back(tmp.second);
      node.first--;
      tmp.first--;
      if (tmp.first)
        que.push(tmp);
    }
    node.first--;
    ans.push_back(node.second);
    if (node.first)
      que.push(node);
  }
  return ans;
}

int main() {
  return 0;
}
