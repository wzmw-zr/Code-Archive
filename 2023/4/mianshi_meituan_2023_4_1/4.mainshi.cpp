/*************************************************************************
	> File Name: 4.mainshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 10时48分36秒
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

vector<long> minCost(vector<long> &volumes, vector<long> &init_vals, vector<long> &costs, vector<int> &queries) {
  int n = volumes.size();
  vector<long> ans;
  for (int q : queries) {
    long volume = 0;
    long min_cost = INT64_MAX;
    for (int i = q - 1; i >= 0; i--) {
      volume += volumes[i] - init_vals[i];
      min_cost = min(min_cost, volume * costs[i]);
    }
    ans.push_back(min_cost);
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n;
  vector<long> arr_x(n), arr_y(n), arr_z(n);
  for (int i = 0; i < n; i++)
    cin >> arr_x[i];
  for (int i = 0; i < n; i++)
    cin >> arr_y[i];
  for (int i = 0; i < n; i++)
    cin >> arr_z[i];
  cin >> m;
  vector<int> queries(m);
  for (int i = 0; i < m; i++)
    cin >> queries[i];
  vector<long> ans = minCost(arr_x, arr_y, arr_z, queries);
  for (int i = 0; i < ans.size(); i++)
    cout << (i == 0 ? "" : " ") << ans[i];
  cout << endl;
  return 0;
}
