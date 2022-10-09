/*************************************************************************
	> File Name: 3.LeetCode6201.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月09日 星期日 10时38分07秒
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

vector<int> findArray(vector<int>& pref) {
  int n = pref.size();
  vector<int> ans(n);
  ans[0] = pref[0];
  for (int i = 1; i < n; i++)
    ans[i] = pref[i] ^ pref[i - 1];
  return ans;
}

int main() {
  return 0;
}
