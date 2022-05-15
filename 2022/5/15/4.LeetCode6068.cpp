/*************************************************************************
	> File Name: 4.LeetCode6068.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月15日 星期日 11时12分11秒
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

int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
  sort(tiles.begin(), tiles.end());
  int n = tiles.size();
  int l = 0, r = 0;
  int ans = 0;
  int cnt = 0;
  while (r < n) {
    while (r < n && tiles[r][1] <= tiles[l][0] + carpetLen - 1) {
      cnt += tiles[r][1] - tiles[r][0] + 1;
      r++;
    }
    if (r < n) {
      int rest = max(tiles[l][0] + carpetLen - tiles[r][0], 0);
      ans = max(ans, cnt + rest);
      cnt -= tiles[l][1] - tiles[l][0] + 1;
      l++;
    } else {
      ans = max(ans, cnt);
    }
  }
  return ans;
}

int main() {
  return 0;
}
