/*************************************************************************
	> File Name: 3.LeetCode6134.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月31日 星期日 10时37分50秒
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


void dfs(vector<int> &edges, unordered_map<int, int> &mp, vector<int> &check, int ind, int dist) {
  if (check[ind]) return ;
  mp[ind] = dist;
  check[ind] = 1;
  if (edges[ind] == -1) return ;
  dfs(edges, mp, check, edges[ind], dist + 1);
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
  int n = edges.size();
  unordered_map<int, int> reachable_node_dist_1;
  unordered_map<int, int> reachable_node_dist_2;
  vector<int> check1(n, 0);
  vector<int> check2(n, 0);
  dfs(edges, reachable_node_dist_1, check1, node1, 0);
  dfs(edges, reachable_node_dist_2, check2, node2, 0);
  int ans = n, min_dis = INT32_MAX;
  for (auto && [ind, dis] : reachable_node_dist_1) {
    if (!reachable_node_dist_2.count(ind)) continue;
    int max_dis = max(dis, reachable_node_dist_2[ind]);
    if (min_dis > max_dis)
      min_dis = max_dis, ans = ind;
    else if (min_dis == max_dis)
      ans = min(ans, ind);
  }
  return min_dis == INT32_MAX ? -1 : ans;
}

int main() {
  return 0;
}
