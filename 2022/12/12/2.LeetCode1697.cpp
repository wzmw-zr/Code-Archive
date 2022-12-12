/*************************************************************************
	> File Name: 2.LeetCode1697.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月12日 星期一 22时48分44秒
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

// WA
struct UnionSet {
  int n;
  vector<int> vals;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int n) : n(n), vals(vector<int>(n, INT32_MIN)), fa(vector<int>(n)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y, int val) {
    int a = get(x);
    int b = get(y);
    fa[a] = b;
    vals[b] = max({vals[a], vals[b], val});
  }
};

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
  sort(edgeList.begin(), edgeList.end(), [](auto && a, auto && b){
    return a[2] < b[2];
  });
  sort(queries.begin(), queries.end(), [](auto && a, auto && b){
    return a[2] < b[2];
  });
  UnionSet u(n);
  int ind = 0;
  vector<bool> ans;
  for (auto && q : queries) {
    while (ind < edgeList.size() && edgeList[ind][2] < q[2]) {
      u.merge(edgeList[ind][0], edgeList[ind][1], edgeList[ind][2]);
      ind++;
    }
    ans.push_back(u.get(q[0]) == u.get(q[1]));
  }
  return ans;
}

int main() {
  return 0;
}
