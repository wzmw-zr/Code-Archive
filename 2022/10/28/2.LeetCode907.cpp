/*************************************************************************
	> File Name: 2.LeetCode907.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月28日 星期五 09时47分29秒
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

long MOD = 1e9 + 7;

int sumSubarrayMins(vector<int>& arr) {
  int n = arr.size();
  long ans = 0;
  vector<int> st;
  st.push_back(-1);
  for (int i = 0; i < n; i++) {
    while (st.size() != 1 && arr[*st.rbegin()] > arr[i]) {
      int m = st.size();
      ans = (ans + 1L * arr[st[m - 1]] * (st[m - 1] - st[m - 2]) * (i - st[m - 1])) % MOD;
      st.pop_back();
    }
    st.push_back(i);
  }
  while (st.size() != 1) {
    int m = st.size();
    ans = (ans + 1L * arr[st[m - 1]] * (n - st[m - 1]) * (st[m - 1] - st[m - 2])) % MOD;
    st.pop_back();
  }
  return ans;
}

int main() {
  return 0;
}
