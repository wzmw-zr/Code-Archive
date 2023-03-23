/*************************************************************************
	> File Name: 1.Leetcode1630.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月23日 星期四 09时42分39秒
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

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
  int n = nums.size(), m = l.size();
  vector<bool> ans(m);
  for (int i = 0; i < m; i++) {
    vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
    sort(temp.begin(), temp.end());
    int k = temp.size();
    bool res = true;
    for (int i = 2; i < k; i++) {
      if (temp[i] - temp[i - 1] == temp[i - 1] - temp[i - 2])
        continue;
      res = false;
      break;
    }
    ans[i] = res;
  }
  return ans;
}

int main() {
  return 0;
}
