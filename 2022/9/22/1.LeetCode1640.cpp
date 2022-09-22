/*************************************************************************
	> File Name: 1.LeetCode1640.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月22日 星期四 08时59分50秒
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

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
  map<int, int> mp1, mp2;
  for (int x : arr)
    mp1[x]++;
  for (auto && piece : pieces) {
    for (int x : piece)
      mp2[x]++;
  }
  if (mp1 != mp2)
    return false;
  int n = arr.size();
  for (auto && piece : pieces) {
    int m = piece.size();
    int valid = 0;
    for (int i = 0; i <= n - m; i++) {
      int flag = 0;
      for (int j = 0; j < m; j++) {
        if (arr[i + j] == piece[j])
          continue;
        flag = 1;
        break;
      }
      if (!flag) {
        valid = 1;
        break;
      }
    }
    if (!valid) 
      return false;
  }
  return true;
}

int main() {
  return 0;
}
