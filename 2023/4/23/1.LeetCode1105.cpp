/*************************************************************************
	> File Name: 1.LeetCode1105.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月23日 星期日 09时55分16秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
  int n = books.size();
  int dp[n + 1];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int width = 0, height = 0;
    for (int j = i; j >= 1 && width + books[j - 1][0] <= shelfWidth; j--) {
      width += books[j - 1][0];
      height = max(height, books[j - 1][1]);
      dp[i] = min(dp[i], dp[j - 1] + height);
    }
  }
  return dp[n];
}

int main() {
  return 0;
}
