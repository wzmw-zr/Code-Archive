/*************************************************************************
	> File Name: 1.LeetCode946.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月31日 星期三 09时11分22秒
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

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  int n = pushed.size();
  int ind_1 = 0, ind_2 = 0;
  unordered_set<int> st;
  stack<int> stk;
  while (ind_2 < n) {
    int x = popped[ind_2];
    if (st.count(x)) {
      if (stk.top() == x) 
        stk.pop();
      else
        return false;
      ind_2++;
    } else {
      while (ind_1 < n && pushed[ind_1] != x) {
        stk.push(pushed[ind_1]);
        st.insert(pushed[ind_1]);
        ind_1++;
      }
      if (ind_1 == n)
        return false;
      stk.push(pushed[ind_1]);
      st.insert(pushed[ind_1]);
      ind_1++;
    }
  }
  return true;
}

int main() {
  return 0;
}
