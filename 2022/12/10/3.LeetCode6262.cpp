/*************************************************************************
	> File Name: 3.LeetCode6262.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月10日 星期六 22时36分03秒
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
  vector<int> next;

  Node() = default;
  Node(int ind) : ind(ind) {}
};

int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
  int n = vals.size();
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i));
  for (auto && edge : edges) {
    graph[edge[0]].next.push_back(edge[1]);
    graph[edge[1]].next.push_back(edge[0]);
  }
  int ans = INT32_MIN;
  for (int i = 0; i < n; i++) {
    sort(graph[i].next.begin(), graph[i].next.end(), [&](int a, int b){
      return vals[a] > vals[b];
    });
    int sum = vals[i];
    for (int j = 0; j < k && j < graph[i].next.size() && vals[graph[i].next[j]] > 0; j++) 
      sum += vals[graph[i].next[j]];
    ans = max(ans, sum);
  }
  return ans;
}

int main() {
  return 0;
}
