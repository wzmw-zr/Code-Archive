/*************************************************************************
	> File Name: 4.LeetCode6085.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月28日 星期六 22时45分32秒
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

long long maximumImportance(int n, vector<vector<int>>& roads) {
  vector<long long> deg(n, 0);
  for (auto road : roads) {
    deg[road[0]]++;
    deg[road[1]]++;
  }
  sort(deg.begin(), deg.end());
  long long ans = 0;
  for (long long i = n - 1; i >= 0; i--) {
    ans += (i + 1) * deg[i];
  }
  return ans;
}

int main() {
  return 0;
}
