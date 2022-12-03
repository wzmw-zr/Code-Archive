/*************************************************************************
	> File Name: 1.LeetCode1796.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月03日 星期六 09时53分20秒
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

int secondHighest(string s) {
  set<int> st;
  for (char c : s) {
    if (c >= '0' && c <= '9')
      st.insert(c - '0');
  }
  if (st.size() < 2)
    return -1;
  return *(prev(prev(st.end())));
}

int main() {
  return 0;
}
