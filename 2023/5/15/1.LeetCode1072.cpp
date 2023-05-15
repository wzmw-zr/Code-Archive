/*************************************************************************
	> File Name: 1.LeetCode1072.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月15日 星期一 09时33分35秒
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

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
  int m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> states(m, vector<int>(0));
  int cnt = n / 32 + ((n % 32) ? 1 : 0);
  vector<int> all_zeros(cnt, 0);
  vector<int> all_ones(cnt, 0);
  for (int i = 0; i < cnt; i++) {
    int base = 0;
    for (int j = i * 32; j < min(i * 32 + 32, n); j++) {
      base <<= 1;
      base += 1;
    }
    for (int j = n; j < i * 32 + 32; j++)
      base <<= 1;
    all_ones[i] = base;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < cnt; j += 1) {
      int val = 0;
      for (int k = j * 32; k < min(j * 32 + 32, n); k++) {
        val <<= 1;
        val += matrix[i][k];
      }
      for (int k = n; k < j * 32 + 32; k++)
        val <<= 1;
      states[i].push_back(val);
    }
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    vector<int> tmp(cnt, 0);

    for (int j = 0; j < cnt; j++)
      tmp[j] = all_zeros[j] ^ states[i][j];
    int num = 0;
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < cnt; k++) {
        states[j][k] ^= tmp[k];
      }
      if (states[j] == all_zeros || states[j] == all_ones)
        num++;
      for (int k = 0; k < cnt; k++) {
        states[j][k] ^= tmp[k];
      }
    }
    ans = max(ans, num);

    for (int j = 0; j < cnt; j++)
      tmp[j] = all_ones[j] ^ states[i][j];
    num = 0;
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < cnt; k++) {
        states[j][k] ^= tmp[k];
      }
      if (states[j] == all_zeros || states[j] == all_ones)
        num++;
      for (int k = 0; k < cnt; k++) {
        states[j][k] ^= tmp[k];
      }
    }
    
    ans = max(ans, num);
  }
  return ans;
}

int main() {
  return 0;
}
