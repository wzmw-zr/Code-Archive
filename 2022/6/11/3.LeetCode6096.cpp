/*************************************************************************
	> File Name: 3.LeetCode6096.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月11日 星期六 22时36分50秒
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

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
  sort(potions.begin(), potions.end());

  auto find_first_ge = [&](int spell) -> int {
    int n = potions.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      long val = 1L * spell * potions[mid];
      if (val >= success) r = mid;
      else l = mid + 1;
    }
    return 1L * spell * potions[l] >= success ?  n - l : n - l - 1;
  };
  
  int n = spells.size();
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) ans[i] = find_first_ge(spells[i]);
  return ans;
}

int main() {
  return 0;
}
