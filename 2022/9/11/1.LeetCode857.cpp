/*************************************************************************
	> File Name: 1.LeetCode857.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月11日 星期日 10时12分26秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
  int n = quality.size();
  vector<int> inds(n, 0);
  iota(inds.begin(), inds.end(), 0);
  auto cmp = [&](int &a, int &b) -> bool {
    return wage[a] * quality[b] < wage[b] * quality[a];
  };
  sort(inds.begin(), inds.end(), cmp);
  priority_queue<int> que;
  int total_q = 0;
  double ans = INT32_MAX;
  for (int i = 0; i < k - 1; i++) {
    que.push(quality[inds[i]]);
    total_q += quality[inds[i]];
  }
  for (int i = k - 1; i < n; i++) {
    int ind = inds[i];
    que.push(quality[ind]);
    total_q += quality[ind];
    double total_c = ((double) wage[ind] / quality[ind]) * total_q;
    ans = min(ans, total_c);
    total_q -= que.top();
    que.pop();
  }
  return ans;
}

int main() {
  return 0;
}
