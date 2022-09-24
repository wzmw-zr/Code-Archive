/*************************************************************************
	> File Name: 1.LeetCode1652.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月24日 星期六 09时33分58秒
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

vector<int> decrypt(vector<int>& code, int k) {
  int n = code.size();
  vector<int> ans(n, 0);
  if (k == 0) {
    return ans;
  } else if (k > 0) {
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 1; j <= k; j++) 
        sum += code[(i + j) % n];
      ans[i] = sum;
    }
  } else {
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = -1; j >= k; j--) 
        sum += code[(i + j + n) % n];
      ans[i] = sum;
    }
  }
  return ans;
}

int main() {
  return 0;
}
