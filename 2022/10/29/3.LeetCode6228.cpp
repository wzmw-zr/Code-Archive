/*************************************************************************
	> File Name: 3.LeetCode6228.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月29日 星期六 22时38分17秒
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

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
  int n = queries.size();
  int m = dictionary.size();
  int len = queries[0].size();
  vector<string> ans;
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < m; j++) {
      int diff = 0;
      for (int k = 0; k < len; k++)
        diff += queries[i][k] == dictionary[j][k] ? 0 : 1;
      if (diff <= 2) {
        flag = 1;
        break;
      }
    }
    if (flag)
      ans.push_back(queries[i]);
  }
  return ans;
}

int main() {
  return 0;
}
