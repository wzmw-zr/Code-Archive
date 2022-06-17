/*************************************************************************
	> File Name: 1.LeetCode1089.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月17日 星期五 09时17分44秒
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

void duplicateZeros(vector<int>& arr) {
  int n = arr.size();
  vector<int> nums;
  for (int x : arr) {
    if (x == 0) nums.push_back(x);
    nums.push_back(x);
  }
  for (int i = 0; i < n; i++) arr[i] = nums[i];
}

int main() {
  return 0;
}
