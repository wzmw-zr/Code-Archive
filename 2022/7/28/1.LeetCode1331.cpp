/*************************************************************************
	> File Name: 1.LeetCode1331.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月28日 星期四 09时17分43秒
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

vector<int> arrayRankTransform(vector<int>& arr) {
  vector<int> temp = arr;
  sort(temp.begin(), temp.end());
  int ind = 1;
  unordered_map<int, int> mp;
  for (int x : temp) {
    if (mp.count(x)) continue;
    mp[x] = ind++;
  }
  vector<int> ans;
  for (int x : arr) ans.push_back(mp[x]);
  return ans;
}

int main() {
  return 0;
}
