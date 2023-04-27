/*************************************************************************
	> File Name: 2.LeetCode1048.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月27日 星期四 10时50分44秒
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
  int max_len;
  int in_deg;
  vector<int> next;

  Node() = default;
  Node(int ind) : ind(ind), max_len(1), in_deg(0), next(vector<int>(0)) {}
};

int longestStrChain(vector<string>& _words) {
  unordered_set<string> st(_words.begin(), _words.end());
  vector<string> words(st.begin(), st.end());
  unordered_map<string, int> mp;
  int n = words.size();
  for (int i = 0; i < n; i++)
    mp[words[i]] = i;

  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i));

  for (int i = 0; i < n; i++) {
    string &s = words[i];
    for (int j = 0; j <= s.size(); j++) {
      string left = s.substr(0, j);
      string right = s.substr(j);
      for (char c = 'a'; c <= 'z'; c++) {
        string str = left + c + right;
        if (mp.count(str)) {
          graph[i].next.push_back(mp[str]);
          graph[mp[str]].in_deg++;
        }
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
