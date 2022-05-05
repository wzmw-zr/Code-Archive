/*************************************************************************
	> File Name: 2.LeetCode1222.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月05日 星期四 17时32分30秒
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

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
  set<vector<int>> st;
  for (auto && q : queens) st.insert(q);
  int x = king[0], y = king[1];
  vector<vector<int>> ans;
  for (int i = 1; y + i < 8; i++) {
    vector<int> temp({x, y + i});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; y - i >= 0; i++) {
    vector<int> temp({x, y - i});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; x + i < 8; i++) {
    vector<int> temp({x + i, y});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; x - i >= 0; i++) {
    vector<int> temp({x - i, y});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; x + i < 8 && y + i < 8; i++) {
    vector<int> temp({x + i, y + i});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
    vector<int> temp({x - i, y - i});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; x + i < 8 && y - i >= 0; i++) {
    vector<int> temp({x + i, y - i});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  for (int i = 1; x - i >= 0 && y + i < 8; i++) {
    vector<int> temp({x - i, y + i});
    if (st.count(temp)) {
      ans.push_back(temp);
      break;
    }
  }
  return ans;
}

int main() {
  return 0;
}
