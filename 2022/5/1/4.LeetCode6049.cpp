/*************************************************************************
	> File Name: 4.LeetCode6049.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月01日 星期日 10时45分53秒
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

int countDistinct(vector<int>& nums, int k, int p) {
  int n = nums.size();
  set<vector<int>> st;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    int cnt = 0;
    for (int j = 0; i + j < n && cnt <= k; j++) {
      if (nums[i + j] % p == 0) cnt++;
      if (cnt > k) break;
      temp.push_back(nums[i + j]);
      st.insert(temp);
    }
  }
  return st.size();
}

int main() {
  return 0;
}
