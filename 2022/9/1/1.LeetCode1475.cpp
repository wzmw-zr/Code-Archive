/*************************************************************************
	> File Name: 1.LeetCode1475.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月01日 星期四 09时27分32秒
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

vector<int> finalPrices(vector<int>& prices) {
  int n = prices.size();
  stack<int> st;
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && prices[st.top()] > prices[i])
      st.pop();
    if (st.empty())
      ans[i] = prices[i];
    else
      ans[i] = prices[i] - prices[st.top()];
    st.push(i);
  }
  return ans;
}

int main() {
  return 0;
}
