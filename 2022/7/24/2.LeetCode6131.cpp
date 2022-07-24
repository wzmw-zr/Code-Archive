/*************************************************************************
	> File Name: 2.LeetCode6131.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月24日 星期日 09时39分23秒
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

int shortestSequence(vector<int>& rolls, int k) {
  unordered_set<int> st;
  int ans = 0;
  for (int x : rolls) {
    st.insert(x);
    if (st.size() == k) {
      st.clear();
      ans++;
    }
  }
  return ans + 1;
}

int main() {
  return 0;
}
