/*************************************************************************
	> File Name: 2.LeetCode710.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月26日 星期日 09时53分57秒
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

// WA
class Solution {
public:
  int mmax;
  vector<int> cnts;
  vector<int> blacklist;

  Solution(int n, vector<int>& blacklist) : mmax(n - blacklist.size()), cnts(vector<int>(blacklist.size())), blacklist(blacklist) {
    srand(time(0));
    int m = blacklist.size();
    for (int i = 0; i < m; i++) cnts[i] = blacklist[i] - (i + 1);
  }

  int pick() {
    int ind = rand() % mmax;
    int l = 0, r = (int) blacklist.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (cnts[mid] < ind) l = mid;
      else r = mid - 1;
    }
    int dis = ind - cnts[l];
    return blacklist[l] + dis;
  }
};

int main() {
  return 0;
}
