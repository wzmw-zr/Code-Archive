/*************************************************************************
	> File Name: 1.LeetCode952.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月30日 星期六 09时12分38秒
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

const int MMAX = 1e5 + 10;

struct UnionSet {
  int n;
  vector<int> cnts;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int num, vector<int> &nums) : n(num + 5), cnts(vector<int>(num + 10, 0)), fa(vector<int>(num + 10)) {
    for (int x : nums) cnts[x] = 1;
    for (int i = 0; i <= n; i++) fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b) return ;
    fa[a] = b;
    cnts[b] += cnts[a];
  }
};

int largestComponentSize(vector<int>& nums) {
  UnionSet u(MMAX, nums);
  unordered_set<int> st;
  for (int x : nums) st.insert(x);
  vector<int> check(MMAX + 10, 0);
  for (int i = 2; i <= MMAX; i++) {
    if (check[i]) continue;
    vector<int> temp;
    for (int j = 1; j * i <= MMAX; j++) {
      if (st.count(j * i)) 
        temp.push_back(i * j);
      check[i * j] = 1;
    }
    int n = temp.size();
    for (int i = 0; i < n - 1; i++) u.merge(temp[i], temp[i + 1]);
  }
  int ans = 0;
  for (int i = 2; i <= MMAX; i++) 
    ans = max(ans, u.cnts[u.get(i)]);
  return ans;
}

int main() {
  return 0;
}
