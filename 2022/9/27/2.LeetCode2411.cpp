/*************************************************************************
	> File Name: 2.LeetCode2411.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月27日 星期二 09时50分38秒
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


vector<int> smallestSubarrays(vector<int>& nums) {
  int n = nums.size();
  vector<int> suf(n + 1, 0);
  vector<vector<int>> nearest_inds(32, vector<int>(n + 1, n));
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] | nums[i];
    for (int j = 0; j <= 31; j++) {
      nearest_inds[j][i] = nearest_inds[j][i + 1];
      if (nums[i] & (1 << j))
        nearest_inds[j][i] = i;
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int pos = i;
    for (int j = 0; j <= 31; j++) {
      if (suf[i] & (1 << j)) 
        pos = max(pos, nearest_inds[j][i]);
    }
    ans[i] = pos - i + 1;
  }
  return ans;
}


int main() {
  return 0;
}
