/*************************************************************************
	> File Name: 4.LeetCode6363.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 10时41分28秒
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

vector<vector<int>> findMatrix(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int> mp;
  for (int x : nums)
    mp[x]++;
  vector<vector<int>> ans;
  while (n) {
    vector<int> temp;
    for (auto && [x, cnt] : mp) {
      if (!cnt)
        continue;
      temp.push_back(x);
      mp[x]--;
      n--;
    }
    ans.push_back(temp);
  }
  return ans;
}

int main() {
  return 0;
}
