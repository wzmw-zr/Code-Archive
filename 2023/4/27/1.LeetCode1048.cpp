/*************************************************************************
	> File Name: 1.LeetCode1048.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月27日 星期四 09时28分03秒
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
  int ind;
  int max_len;
  int in_deg;
  vector<int> next;

  Node() = default;
  Node(int ind) : ind(ind), max_len(1), in_deg(0), next(vector<int>(0)) {}
};

bool check(string &s1, string &s2) {
  if (s2.size() != s1.size() + 1)
    return false;
  int n = s1.size();
  int len_1 = 0, len_2 = 0;
  while (s1[len_1] && s2[len_1] && s1[len_1] == s2[len_1])
    len_1++;
  while (len_2 < n && s1[n - 1 - len_2] == s2[n - len_2])
    len_2++;
  if (len_1 == n || len_2 == n || len_1 + len_2 == n)
    return true;
  return false;
}

int longestStrChain(vector<string>& words) {
  int n = words.size();
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (check(words[i], words[j])) {
        graph[i].next.push_back(j);
        graph[j].in_deg++;
      }
    }
  }

  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (!graph[i].in_deg)
      que.push(i);
  }

  int ans = 1;
  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    ans = max(ans, graph[ind].max_len);
    for (int x : graph[ind].next) {
      graph[x].max_len = max(graph[x].max_len, graph[ind].max_len + 1);
      if (!(--graph[x].in_deg))
        que.push(x);
    }
  }
  return ans;
}

int main() {
  return 0;
}
