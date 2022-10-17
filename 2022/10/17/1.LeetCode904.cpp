/*************************************************************************
	> File Name: 1.LeetCode904.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月17日 星期一 09时09分51秒
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

int totalFruit(vector<int>& fruits) {
  int l = 0, r = 0, n = fruits.size();
  int ans = 0;
  unordered_map<int, int> mp;
  while (r < n) {
    while (r < n) {
      mp[fruits[r]]++;
      if (mp.size() == 3)
        break;
      r++;
    }
    ans = max(ans, r - l);
    if (mp.size() == 3) {
      while (l < r && mp.size() == 3) {
        if (!(--mp[fruits[l]])) 
          mp.erase(fruits[l]);
        l++;
      }
      r++;
    } 
  }
  return ans;
}

int main() {
  return 0;
}
