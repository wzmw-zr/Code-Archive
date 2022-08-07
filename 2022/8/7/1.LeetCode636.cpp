/*************************************************************************
	> File Name: 1.LeetCode636.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月07日 星期日 09时28分46秒
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
  int interval;

  Node() = default;
  Node(int id) : id(id), interval(0) {}
};

vector<int> exclusiveTime(int n, vector<string>& logs) {
  vector<int> intervals(n, 0);
  stack<Node> st;
  int pre = 0;
  for (string &log : logs) {
    int id;
    string phase = "";
    int point;
    int ind = 0;

    string s = "";
    while (log[ind] != ':') 
      s += log[ind++];
    id = stoi(s);
    ind++;

    while (log[ind] != ':') 
      phase += log[ind++];
    ind++;

    point = stoi(log.substr(ind));

    if (phase == "start") {
      if (!st.empty()) 
        st.top().interval += point - pre;
      st.push(Node(id));
      pre = point;
    } else {
      st.top().interval += point - pre + 1;
      intervals[st.top().id] += st.top().interval;
      st.pop();
      pre = point + 1;
    }
  }
  return intervals;
}

int main() {
  return 0;
}
