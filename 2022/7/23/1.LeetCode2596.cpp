/*************************************************************************
	> File Name: 1.LeetCode2596.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月23日 星期六 09时19分53秒
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
  int ind;
  int in_deg;
  vector<int> next;

  Node() = default;
  Node(int ind) : ind(ind), in_deg(0), next(vector<int>(0)) {}
};

bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
  if (nums.size() == 1) return true;
  unordered_map<int, Node> mp;
  for (auto && seq : sequences) {
    int n = seq.size();
    for (int i = 0; i < n - 1; i++) {
      if (!mp.count(seq[i])) mp[seq[i]] = Node(seq[i]);
      mp[seq[i]].next.push_back(seq[i + 1]);
      if (!mp.count(seq[i + 1])) mp[seq[i + 1]] = Node(seq[i + 1]);
      mp[seq[i + 1]].in_deg++;
    }
  }
  queue<int> que;
  for (auto && [ind, node] : mp) {
    if (node.in_deg == 0) que.push(ind);
  }
  vector<int> res;
  while (que.size() == 1) {
    int ind = que.front();
    que.pop();
    res.push_back(ind);
    for (int x : mp[ind].next) {
      if (!(--mp[x].in_deg)) 
        que.push(x);
    }
  }
  if (que.size() > 0) return false;
  return res == nums;
}

int main() {
  return 0;
}
