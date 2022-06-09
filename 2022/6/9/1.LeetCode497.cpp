/*************************************************************************
	> File Name: 1.LeetCode497.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月09日 星期四 09时31分21秒
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

class Solution {
public:
  vector<vector<int>> rects;

  int total;

  Solution(vector<vector<int>>& rects) : total(0), rects(rects) {
    srand(time(0));
    for (auto && rec : rects) 
      total += (rec[2] - rec[0] + 1) * (rec[3] - rec[1] + 1);
  }

  vector<int> pick() {
    int ind = (rand() % total) + 1;
    for (auto && rec : rects) {
      int cnt = (rec[2] - rec[0] + 1) * (rec[3] - rec[1] + 1);
      if (cnt < ind) ind -= cnt;
      else {
        int h = rec[3] - rec[1] + 1;
        int w = rec[2] - rec[0] + 1;
        ind -= 1;
        int off_y = ind / w;
        int off_x = ind % w;
        return {rec[0] + off_x, rec[1] + off_y};
      }
    }
    return {-1, -1};
  }
};

int main() {
  return 0;
}
