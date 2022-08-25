/*************************************************************************
	> File Name: 2.LeetCode658.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月25日 星期四 09时46分42秒
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

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  auto cmp = [&](int a, int b) -> bool {
    return abs(a - x) == abs(b - x) ? a < b : abs(a - x) < abs(b - x);
  };
  sort(arr.begin(), arr.end(), cmp);
  vector<int> ans(arr.begin(), arr.begin() + k);
  sort(ans.begin(), ans.end());
  return ans;
}


int main() {
  return 0;
}
