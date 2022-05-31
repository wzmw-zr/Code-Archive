/*************************************************************************
	> File Name: 1.LeetCode2542.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月31日 星期二 09时24分57秒
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
  char c;
  unordered_set<char> next;
  int in_deg;

  Node() = default;
  Node(char c) : c(c), next(unordered_set<char>()), in_deg(0) {}
};

void build_graph(unordered_map<char, Node> &graph, vector<string> &words) {
  if (words.size() <= 1) return ;
  vector<char> chs;
  for (auto word : words) {
    if (chs.size() == 0 || *chs.rbegin() != word[0]) chs.push_back(word[0]);
  }
  int n = chs.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (graph[chs[i]].next.count(chs[j])) continue;
      graph[chs[i]].next.insert(chs[j]);
      graph[chs[j]].in_deg++;
    }
  }
  for (int i = 0; i < n; i++) {
    vector<string> temp;
    for (auto && word : words) {
      if (word[0] == chs[i] && word.size() > 1) 
        temp.push_back(word.substr(1));
    }
    build_graph(graph, temp);
  }
}

string alienOrder(vector<string>& words) {
  int n = words.size();
  for (int i = 1; i < n; i++) {
    if (words[i - 1].size() > words[i].size()) {
      if (words[i - 1].substr(0, words[i].size()) == words[i]) return "";
    }
  }
  unordered_map<char, Node> graph;
  for (auto && word : words) {
    for (auto && c : word) {
      if (graph.count(c)) continue;
      graph[c] = Node(c);
    }
  }
  build_graph(graph, words);
  queue<char> que;
  for (auto &&[c, node] : graph) {
    if (node.in_deg == 0) que.push(c);
  }
  string ans = "";
  while (!que.empty()) {
    auto t = que.front();
    que.pop();
    ans += t;
    for (char c : graph[t].next) {
      if (!(--graph[c].in_deg)) que.push(c);
    }
  }
  for (auto &&[c, node] : graph) {
    if (node.in_deg) return "";
  }
  return ans;
}

int main() {
  return 0;
}
