/*************************************************************************
	> File Name: 2.LeetCode2454.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月03日 星期四 10时30分22秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<int> secondGreaterElement(vector<int>& nums) {
  int n = nums.size();
  stack<int> st1, st2;
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    while (!st2.empty() && nums[st2.top()] < nums[i]) {
      ans[st2.top()] = nums[i];
      st2.pop();
    }
    vector<int> temp;
    while (!st1.empty() && nums[st1.top()] < nums[i]) {
      temp.push_back(st1.top());
      st1.pop();
    }
    st1.push(i);
    for (auto iter = temp.rbegin(); iter != temp.rend(); iter++)
      st2.push(*iter);
  }
  return ans;
}

int main() {
  return 0;
}
