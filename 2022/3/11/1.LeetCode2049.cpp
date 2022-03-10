/*************************************************************************
	> File Name: 1.LeetCode2049.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月11日 星期五 00时21分14秒
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

// WA
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
  vector<int> child;
  int out_degree;
  int size;
  int score;

  Node() : child(vector<int>(0)), out_degree(0), size(1), score(1) {}
};

int countHighestScoreNodes(vector<int>& parents) {
  int n = parents.size();
  vector<Node> nodes(n + 1);
  for (int i = 1; i < n; i++) {
    nodes[parents[i]].child.push_back(i);
    nodes[parents[i]].out_degree++;
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (nodes[i].out_degree == 0) que.push(i);
  }
  map<int, int> mp;
  while (!que.empty()) {
    int t = que.front();
    que.pop();
    if (nodes[t].child.size() == 0) nodes[t].score = 0;
    mp[nodes[t].score]++;
    if (parents[t] != -1) {
      nodes[parents[t]].score *= nodes[t].size;
      nodes[parents[t]].size += nodes[t].size;
      if (!(--nodes[parents[t]].out_degree)) que.push(parents[t]);
    }
  }
  return prev(mp.end())->second;
}

int main() {
  return 0;
}
