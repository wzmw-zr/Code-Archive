/*************************************************************************
	> File Name: 5.LeetCode6364.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 10时51分30秒
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

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
  int n = reward1.size();
  vector<int> inds;
  for (int i = 0; i < n; i++)
    inds.push_back(i);
  sort(inds.begin(), inds.end(), [&](int x, int y){
    int dis1 = reward1[x] - reward2[x];
    int dis2 = reward1[y] - reward2[y];
    return dis1 == dis2 ? x < y : dis1 > dis2;
  });
  int ans = 0;
  for (int i = 0; i < k; i++) 
    ans += reward1[inds[i]];
  for (int i = k; i < n; i++)
    ans += reward2[inds[i]];
  return ans;
}

int main() {
  return 0;
}
