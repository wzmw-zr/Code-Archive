/*************************************************************************
	> File Name: 1.LeetCode1700.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月19日 星期三 09时10分08秒
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

int countStudents(vector<int>& students, vector<int>& sandwiches) {
  int n = students.size(), m = sandwiches.size();
  stack<int> st;
  for (int i = m - 1; i >= 0; i--)
    st.push(sandwiches[i]);
  queue<int> que;
  for (int i = 0; i < n; i++)
    que.push(students[i]);
  while (!st.empty()) {
    int diff = 0;
    while (que.front() != st.top() && diff != que.size()) {
      int t = que.front();
      que.pop();
      que.push(t);
      diff++;
    }
    if (diff == que.size()) 
      return diff;
    st.pop();
    que.pop();
  }
  return 0;
}

int main() {
  return 0;
}
