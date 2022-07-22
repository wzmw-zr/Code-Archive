/*************************************************************************
	> File Name: 1.LeetCode757.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月22日 星期五 19时21分15秒
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

int intersectionSizeTwo(vector<vector<int>>& intervals) {
  auto cmp = [](vector<int> &a, vector<int> &b) -> bool {
    return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
  };
  sort(intervals.begin(), intervals.end(), cmp);
  int ans = 0;
  int a = -2, b = -1;
  for (auto && x : intervals) {
    if (b < x[0]) {
      a = x[1] - 1;
      b = x[1];
      ans += 2;
    } else if (a < x[0]) {
      a = b;
      b = x[1];
      ans += 1;
    }
  }
  return ans;
}

int main() {
  return 0;
}
