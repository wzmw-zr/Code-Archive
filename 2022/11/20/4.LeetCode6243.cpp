/*************************************************************************
	> File Name: 4.LeetCode6243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月20日 星期日 11时20分09秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
  int n = roads.size() + 1;
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto && road : roads) {
    graph[road[0]].push_back(road[1]);
    graph[road[1]].push_back(road[0]);
  }
  long ans = 0;
  function<long(int, int)> dfs = [&](int root, int fa) -> long {
    long cnt = 1;
    for (int next : graph[root]) {
      if (next == fa)
        continue;
      long num = dfs(next, root);
      ans += num / (1L * seats) + ((num % (1L * seats)) == 0 ? 0 : 1);
      cnt += num;
    }
    return cnt;
  };
  dfs(0, -1);
  return ans;
}

int main() {
  return 0;
}
