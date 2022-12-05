/*************************************************************************
	> File Name: 1.LeetCode6255.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月05日 星期一 10时16分17秒
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

struct UnionSet {
  int n;
  vector<int> fa;
  vector<int> val;

  UnionSet() = default;
  UnionSet(int n) : n(n), fa(vector<int>(n)), val(vector<int>(n, INT32_MAX)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y, int z) {
    int a = get(x), b = get(y);
    if (a == b) {
      val[a] = min(val[a], z);
      return ;
    }
    fa[a] = b;
    val[b] = min({val[a], val[b], z});
  }
};

int minScore(int n, vector<vector<int>>& roads) {
  UnionSet u(n + 1);
  for (auto && road : roads) 
    u.merge(road[0], road[1], road[2]);
  return u.val[u.get(1)];
}

int main() {
  return 0;
}
