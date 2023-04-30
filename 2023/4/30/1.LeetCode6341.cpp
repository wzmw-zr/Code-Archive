/*************************************************************************
	> File Name: 1.LeetCode6341.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月30日 星期日 10时31分56秒
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

int calculate(vector<int> &nums) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int multi = 1;
    if (i >= 1 && nums[i - 1] == 10)
      multi = 2;
    if (i >= 2 && (nums[i - 1] == 10 || nums[i - 2] == 10))
      multi = 2;
    ans += nums[i] * multi;
  }
  return ans;
}

int isWinner(vector<int>& player1, vector<int>& player2) {
  int x1 = calculate(player1);
  int x2 = calculate(player2);
  return x1 == x2 ? 0 : (x1 > x2 ? 1 : 2);
}

int main() {
  return 0;
}
