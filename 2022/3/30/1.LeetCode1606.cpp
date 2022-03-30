/*************************************************************************
	> File Name: 1.LeetCode1606.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月30日 星期三 21时08分17秒
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
  int end_time;

  Node() = default;
  Node(int ind, int end_time) : ind(ind), end_time(end_time) {}

  bool operator<(const struct Node &that) const {
    return this->end_time == that.end_time ? this->ind > that.ind : this->end_time > that.end_time;
  }
};

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
  vector<int> cnts(k, 0);
  priority_queue<Node> que;
  set<int> st;
  for (int i = 0; i < k; i++) st.insert(i);
  int n = arrival.size();
  for (int i = 0; i < n; i++) {
    while (!que.empty() && que.top().end_time <= arrival[i]) {
      st.insert(que.top().ind);
      que.pop();
    }
    if (st.empty()) continue;
    auto iter = st.lower_bound(i % k);
    iter = iter == st.end() ? st.begin() : iter;
    cnts[*iter]++;
    que.push(Node(*iter, arrival[i] + load[i]));
    st.erase(*iter);
  }
  int mmax = 0;
  for (int i = 0; i < k; i++) mmax = max(mmax, cnts[i]);
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    if (mmax == cnts[i]) ans.push_back(i);
  }
  return ans;
}

int main() {
  return 0;
}
