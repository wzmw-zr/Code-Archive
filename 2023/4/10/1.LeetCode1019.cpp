/*************************************************************************
	> File Name: 1.LeetCode1019.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月10日 星期一 09时41分56秒
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> nextLargerNodes(ListNode* head) {
  vector<int> vals;
  while (head) {
    vals.push_back(head->val);
    head = head->next;
  }
  int n = vals.size();
  vector<int> ans(n, 0);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && vals[i] > vals[st.top()]) {
      ans[st.top()] = vals[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

int main() {
  return 0;
}
