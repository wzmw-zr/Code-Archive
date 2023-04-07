/*************************************************************************
	> File Name: 1.LeetCode1040.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月07日 星期五 10时26分59秒
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

int min_move(vector<int> &stones) {
  int n = stones.size();
  int l = 0, r = 0;
  int ans = n;
  while (l < n && r < n) {
    while (r < n && (stones[r] - stones[l] + 1 <= n))
      r++;
    if (r - l == n - 1 && stones[r - 1] - stones[l] + 1 == n - 1)
      ans = min(ans, 2);
    else
      ans = min(ans, n - (r - l));
    l++;
  }
  return ans;
}

int max_move(vector<int> &stones) {
  int n = stones.size();
  int ans = 0;
  if (stones[1] - stones[0] < stones[n - 1] - stones[n - 2]) {
    ans = 1 + (stones[n - 1] - stones[0] + 1 - n - (stones[1] - stones[0]));
  } else {
    ans = 1 + (stones[n - 1] - stones[0] + 1 - n - (stones[n - 1] - stones[n - 2]));
  }
  return ans;
}

vector<int> numMovesStonesII(vector<int>& stones) {
  sort(stones.begin(), stones.end());
  return {min_move(stones), max_move(stones)};
}

int main() {
  return 0;
}
