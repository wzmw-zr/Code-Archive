/*************************************************************************
	> File Name: 1.LeetCode1053.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月03日 星期一 09时43分37秒
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

using PII = pair<int, int>;

vector<int> prevPermOpt1(vector<int>& arr) {
  int n = arr.size();
  set<PII> st;
  for (int i = n - 1; i >= 0; i--) {
    PII val(arr[i] * -1 + 1, i);
    auto iter = st.lower_bound(val);
    if (iter != st.end()) {
      int ind = iter->second;
      swap(arr[i], arr[ind]);
      break;
    }
    val = PII(arr[i] * -1, i);
    st.insert(val);
  }
  return arr;
}

int main() {
  return 0;
}
