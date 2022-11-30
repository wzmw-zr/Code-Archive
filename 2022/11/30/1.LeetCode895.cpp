/*************************************************************************
	> File Name: 1.LeetCode895.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月30日 星期三 11时11分43秒
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
  int val;
  int cnt;
  int last_ind;

  Node() = default;
  Node(int val, int cnt, int last_ind) : val(val), cnt(cnt), last_ind(last_ind) {}

  bool operator<(const struct Node &that) const {
    return this->cnt == that.cnt ? this->last_ind < that.last_ind : this->cnt < that.cnt;
  }
};

class FreqStack {
public:
  int ind;
  map<int, vector<int>> mp_1;
  map<int, Node> mp_2;
  set<Node> st;

  FreqStack() : ind(0) {}

  void push(int val) {
    if (!mp_1.count(val)) {
      mp_1[val] = vector<int>({ind});
      mp_2[val] = Node(val, 1, ind);
      st.insert(mp_2[val]);
    } else {
      mp_1[val].push_back(ind);
      st.erase(mp_2[val]);
      Node node = mp_2[val];
      node.cnt++, node.last_ind = ind;
      mp_2[val] = node;
      st.insert(node);
    }
    ind++;
  }

  int pop() {
    Node node = *st.rbegin();
    st.erase(prev(st.end()));
    int val = node.val;
    mp_1[val].pop_back();
    if (mp_1[val].size()) {
      mp_2[val].cnt--;
      mp_2[val].last_ind = *mp_1[val].rbegin();
      st.insert(mp_2[val]);
    } else {
      mp_1.erase(val);
      mp_2.erase(val);
    }
    return val;
  }
};

int main() {
  return 0;
}
