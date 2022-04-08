/*************************************************************************
	> File Name: 1.LeetCode780.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月09日 星期六 00时24分05秒
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

bool reachingPoints(int sx, int sy, int tx, int ty) {
  while (tx >= sx && ty >= sy) {
    if (tx == sx && ty == sy) return true;
    if (tx > ty) {
      int k = (tx - sx) / ty;
      if (k == 0) return false;
      tx -= k * ty;
    } else {
      int k = (ty - sy) / tx;
      if (k == 0) return false;
      ty -= k * tx;
    }
  }
  return false;
}

int main() {
  return 0;
}
