/*************************************************************************
	> File Name: 3.LeetCode6149.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月14日 星期日 10时37分14秒
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

int edgeScore(vector<int>& edges) {
  int n = edges.size();
  vector<long> vals(n, 0);
  for (int i = 0; i < n; i++)
    vals[edges[i]] += i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vals[i] > vals[ans])
      ans = i;
  }
  return ans;
}

int main() {
  return 0;
}
