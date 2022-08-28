/*************************************************************************
	> File Name: 4.LeetCode6162.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月28日 星期日 10时46分13秒
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

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
  int n = garbage.size();
  vector<int> cnt1(n, 0), cnt2(n, 0), cnt3(n, 0);
  for (int i = 0; i < n; i++) {
    for (char c : garbage[i]) {
      if (c == 'M')
        cnt1[i]++;
      else if (c == 'P')
        cnt2[i]++;
      else 
        cnt3[i]++;
    }
  }
  int ind1 = n - 1, ind2 = n - 1, ind3 = n - 1;
  while (ind1 >= 0 && cnt1[ind1] == 0) 
    ind1--;
  while (ind2 >= 0 && cnt2[ind2] == 0) 
    ind2--;
  while (ind3 >= 0 && cnt3[ind3] == 0) 
    ind3--;
  int ans = 0;
  for (int i = 0; i <= ind1; i++) {
    ans += cnt1[i];
    if (i >= 1) 
      ans += travel[i - 1];
  }
  for (int i = 0; i <= ind2; i++) {
    ans += cnt2[i];
    if (i >= 1) 
      ans += travel[i - 1];
  }
  for (int i = 0; i <= ind3; i++) {
    ans += cnt3[i];
    if (i >= 1) 
      ans += travel[i - 1];
  }
  return ans;
}

int main() {
  return 0;
}
