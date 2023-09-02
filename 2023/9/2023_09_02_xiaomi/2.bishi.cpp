/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月02日 星期六 16时33分45秒
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

struct Node {
  long cost;
  long min_val;

  Node() = default;
  Node(long cost, long min_val) : cost(cost), min_val(min_val) {}

  bool operator<(const struct Node &that) const {
    return this->cost == that.cost ? this->min_val > that.min_val : this->cost < that.cost;
  }
  // bool operator<(const struct Node &that) const {
  //   return this->min_val == that.min_val ? this->cost < that.cost : this->min_val > that.min_val;
  // }
};

long check(long val, vector<Node> &nodes) {
  for (auto && node : nodes) {
    if (val < node.min_val || val < node.cost)
      return 0;
    val -= node.cost;
  }
  return val >= 0;
}

int main() {
  string s;
  getline(cin, s);
  long ind = 0;
  vector<Node> nodes;
  while (s[ind]) {
    string cost, min_val;
    while (s[ind] && s[ind] != ':')
      cost += s[ind++];
    ind++;
    while (s[ind] && s[ind] != ',')
      min_val += s[ind++];
    if (s[ind])
      ind++;
    long x = stol(cost), y = stol(min_val);
    nodes.push_back(Node(x, y));
  }
  sort(nodes.begin(), nodes.end());
  long l = 1, r = 4800;
  while (l < r) {
    long mid = (l + r) / 2;
    if (check(mid, nodes))
      r = mid;
    else
      l = mid + 1;
  }
  cout << (check(l, nodes) ? l : -1) << endl;
  return 0;
}
