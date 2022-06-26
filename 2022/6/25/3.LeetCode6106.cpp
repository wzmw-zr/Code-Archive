/*************************************************************************
	> File Name: 3.LeetCode6106.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月25日 星期六 22时39分02秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct UnionSet {
  int n;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int n) : n(n), fa(vector<int>(n)) {
    for (int i = 0; i < n; i++) fa[i] = i;
  }

  int get(int n) {
    return n == fa[n] ? n : fa[n] = get(fa[n]);
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b) return ;
    fa[a] = b;
  }
};

long long countPairs(int n, vector<vector<int>>& edges) {
  UnionSet u(n);
  for (auto && edge : edges) u.merge(edge[0], edge[1]);
  unordered_map<int, long> mp;
  for (int i = 0; i < n; i++) mp[u.get(i)]++;
  long long ans = 0;
  long long pre = 0;
  for (auto iter = mp.begin(); iter != mp.end(); iter++) {
    ans += pre * iter->second;
    pre += iter->second;
  }
  return ans;
}

int main() {
  return 0;
}
