/*************************************************************************
	> File Name: 1.LeetCode646.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月03日 星期六 09时09分06秒
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

struct Node {
  int id;
  int in_deg;
  vector<int> next;

  Node() : id(0), in_deg(0), next(vector<int>(0)) {}
  Node(int id) : id(id), in_deg(0), next(vector<int>(0)) {}
};

using PII = pair<int, int>;

int findLongestChain(vector<vector<int>>& pairs) {
  int n = pairs.size();
  vector<Node> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i].id = i;
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (pairs[i][1] < pairs[j][0]) {
        nodes[i].next.push_back(j);
        nodes[j].in_deg++;
      }
    }
  }
  int ans = 0;
  queue<PII> que;
  for (int i = 0; i < n; i++) {
    if (!nodes[i].in_deg)
      que.push(PII(i, 1));
  }
  while (!que.empty()) {
    PII t = que.front();
    que.pop();
    auto [id, len] = t;
    ans = max(ans, len);
    for (int x : nodes[id].next) {
      if (!(--nodes[x].in_deg))
        que.push(PII(x, len + 1));
    }
  }
  return ans;
}

int main() {
  return 0;
}
