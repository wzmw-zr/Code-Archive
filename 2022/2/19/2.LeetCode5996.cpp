/*************************************************************************
	> File Name: 2.LeetCode5996.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月19日 星期六 22时30分56秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int countPairs(vector<int>& nums, int k) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((nums[i] == nums[j]) && ((i * j) % k == 0))  
        ans++;
    }
  }
  return ans;
}

int main() {
  return 0;
}
