/*************************************************************************
	> File Name: 1.LeetCode1023.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月14日 星期五 09时11分01秒
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

bool check(string &q, string &p) {
  int n = q.size(), m = p.size();
  int ind_1 = 0, ind_2 = 0;
  while (ind_1 < n && ind_2 < m) {
    while (ind_1 < n && q[ind_1] != p[ind_2]) {
      if (q[ind_1] >= 'A' && q[ind_1] <= 'Z')
        return false;
      ind_1++;
    }
    if (ind_1 == n)
      return false;
    ind_1++, ind_2++;
  }
  if (ind_2 < m)
    return false;
  while (ind_1 < n) {
    if (q[ind_1] >= 'A' && q[ind_1] <= 'Z')
      return false;
    ind_1++;
  }
  return true;
}

vector<bool> camelMatch(vector<string>& queries, string pattern) {
  vector<bool> ans;
  for (string & q : queries) 
    ans.push_back(check(q, pattern));
  return ans;
}

int main() {
  return 0;
}
