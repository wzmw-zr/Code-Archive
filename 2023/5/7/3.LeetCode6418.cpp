/*************************************************************************
	> File Name: 3.LeetCode6418.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月07日 星期日 10时45分30秒
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

vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
  vector<int> colors(n, 0);
  vector<int> ans;
  int cnt = 0;
  for (auto && q : queries) {
    int index = q[0], color = q[1];
    if (index < n - 1) {
      if (colors[index + 1]) {
        if (colors[index] == colors[index + 1]) {
          if (color != colors[index + 1])
            cnt--;
        } else {
          if (color == colors[index + 1])
            cnt++;
        }
      }
    }
    if (index > 0) {
      if (colors[index - 1]) {
        if (colors[index] == colors[index - 1]) {
          if (color != colors[index - 1])
            cnt--;
        } else {
          if (color == colors[index - 1])
            cnt++;
        }
      }
    }
    colors[index] = color;
    ans.push_back(cnt);
  }
  return ans;
}

int main() {
  return 0;
}
