/*************************************************************************
	> File Name: 3.LeetCode6317.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月12日 星期日 10时43分01秒
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

long long beautifulSubarrays(vector<int>& nums) {
  int state = 0;
  unordered_map<int, int> mp;
  mp[state] = 1;
  long long ans = 0;
  for (int x : nums) {
    state ^= x;
    ans += mp[state];
    mp[state]++;
  }
  return ans;
}

int main() {
  return 0;
}
