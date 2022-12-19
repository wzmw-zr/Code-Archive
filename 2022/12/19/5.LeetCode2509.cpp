/*************************************************************************
	> File Name: 5.LeetCode2509.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月19日 星期一 15时17分39秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
  vector<int> ans;
  function<int(int, int)> calc = [&](int x, int y) -> int {
    unordered_map<int, int> mp1;
    int step = 0;
    while (x) {
      mp1[x] = step;
      x /= 2;
      step++;
    }
    step = 0;
    while (y) {
      if (mp1.count(y))
        return mp1[y] + step + 1;
      y /= 2;
      step++;
    }
    return -1;
  };
  for (auto && q : queries)
    ans.push_back(calc(q[0], q[1]));
  return ans;
}

int main() {
  return 0;
}
