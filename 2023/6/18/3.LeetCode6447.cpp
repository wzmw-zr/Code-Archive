/*************************************************************************
	> File Name: 3.LeetCode6447.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月18日 星期日 10时46分06秒
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
#include <numeric>
#include <cstdint>
#include <functional>
using namespace std;


// WA
int paintWalls(vector<int>& cost, vector<int>& time) {
  int n = cost.size();
  function<bool(int, int)> cmp_1 = [&](int a, int b) {
    return cost[a] * time[b] == cost[b] * time[a] ? (time[a] == time[b] ? a < b : time[a] < time[b]) : cost[a] * time[b] < cost[b] * time[a];
  };
  function<bool(int, int)> cmp_2 = [&](int a, int b) {
    return cost[a] == cost[b] ? (time[a] == time[b] ? a < b : time[a] > time[b]) : cost[a] < cost[b];
  };
  set<int, decltype(cmp_1)> st_1(cmp_1);
  set<int, decltype(cmp_2)> st_2(cmp_2);
  for (int i = 0; i < n; i++) {
    st_1.insert(i);
    st_2.insert(i);
  }
  int ans = 0;
  while (st_1.size()) {
    int ind = *st_1.begin();
    st_1.erase(ind);
    st_2.erase(ind);
    ans += cost[ind];
    int t = time[ind];
    while (t && st_2.size()) {
      int idx = *st_2.rbegin();
      st_1.erase(idx);
      st_2.erase(idx);
      t--;
    }
  }
  return ans;
}


int main() {
  // vector<int> cost = {1, 2, 3, 2};
  // vector<int> time = {1, 2, 3, 2};
  vector<int> cost = {2, 3, 4, 2};
  vector<int> time = {1, 1, 1, 1};
  cout << paintWalls(cost, time) << endl;
  return 0;
}
