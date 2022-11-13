/*************************************************************************
	> File Name: 2.LeetCode6237.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月12日 星期六 22时37分36秒
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

int distinctAverages(vector<int>& nums) {
  map<int, int> mp;
  for (int x : nums)
    mp[x]++;
  set<int> st;
  while (mp.size()) {
    int x = mp.begin()->first;
    int y = mp.rbegin()->first;
    if (!(--mp[x]))
      mp.erase(x);
    if (!(--mp[y]))
      mp.erase(y);
    st.insert(x + y);
  }
  return st.size();
}

int main() {
  return 0;
}
