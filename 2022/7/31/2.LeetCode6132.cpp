/*************************************************************************
	> File Name: 2.LeetCode6132.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月31日 星期日 10时30分51秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumOperations(vector<int>& nums) {
  unordered_set<int> st;
  for (int x : nums) {
    if (x > 0) st.insert(x);
  }
  return static_cast<int>(st.size());
}

int main() {
  return 0;
}
