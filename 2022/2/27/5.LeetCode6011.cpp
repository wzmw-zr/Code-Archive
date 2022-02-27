/*************************************************************************
	> File Name: 5.LeetCode6011.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月27日 星期日 16时13分29秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
  int n = tires.size();
  vector<int> minsec(20, INT32_MAX);
  for (int i = 0; i < n; i++) {
    int f = tires[i][0], r = tires[i][1];
    int pre = 0;
    int x = 1;
    for (int j = 1; j <= 18; j++) {
      if (f * pow(r, x - 1) > changeTime + f) {
        x = 1;
        pre += changeTime;
      }
      pre += f * pow(r, x - 1);
      x++;
      minsec[j] = min(minsec[j], pre);
    }
  }
  
  vector<int> dp(numLaps + 1, INT32_MAX);
  dp[0] = -changeTime;
  for (int i = 1; i <= numLaps; i++)
    for (int j = 1; j <= min(i, 18); j++) 
      dp[i] = min(dp[i], dp[i - j] + changeTime + minsec[j]);

  return dp[numLaps];
}

int main() {
  return 0;
}
