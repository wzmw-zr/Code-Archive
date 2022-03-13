/*************************************************************************
	> File Name: 3.LeetCode5203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月13日 星期日 10时39分44秒
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

using PII = pair<int, int>;

int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
  vector<vector<int>> check(n, vector<int>(n, 0));
  map<PII, int> mp;
  for (int i = 0; i < artifacts.size(); i++) {
    for (int x = artifacts[i][0]; x <= artifacts[i][2]; x++) {
      for (int y = artifacts[i][1]; y <= artifacts[i][3]; y++) {
        mp[PII(x, y)] = i;
      }
    }
  }
  int ans = 0;
  for (auto &&d : dig) {
    check[d[0]][d[1]] = 1;
    if (!mp.count(PII(d[0], d[1]))) continue;
    int ind = mp[PII(d[0], d[1])];
    int flag = 1;
    for (int x = artifacts[ind][0]; x <= artifacts[ind][2]; x++) {
      for (int y = artifacts[ind][1]; y <= artifacts[ind][3]; y++) {
        if (check[x][y]) continue;
        flag = 0;
        break;
      }
      if (!flag) break;
    }
    if (flag) ans++;
  }
  return ans;
}

int main() {
  return 0;
}
