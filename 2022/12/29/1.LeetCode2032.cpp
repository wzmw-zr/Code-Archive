/*************************************************************************
	> File Name: 1.LeetCode2032.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月29日 星期四 00时42分59秒
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

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
  set<int> st1(nums1.begin(), nums1.end());
  set<int> st2(nums2.begin(), nums2.end());
  set<int> st3(nums3.begin(), nums3.end());
  set<int> st;
  for (int x : st1) {
    if (st2.count(x))
      st.insert(x);
    if (st3.count(x))
      st.insert(x);
  }
  for (int x : st2) {
    if (st3.count(x))
      st.insert(x);
  }
  return vector<int>(st.begin(), st.end());
}

int main() {
  return 0;
}
