/*************************************************************************
	> File Name: 4.LeetCode6271.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月25日 星期日 11时08分39秒
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

int check(vector<int> &price, int val) {
  int l = 0, r = 1, n = price.size();
  int ans = 1;
  while (r < n) {
    if (price[r] - price[l] >= val) {
      ans++;
      l = r;
    }
    r++;
  }
  return ans;
}

int maximumTastiness(vector<int>& price, int k) {
  sort(price.begin(), price.end());
  int l = 0, r = *price.rbegin() - *price.begin();
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(price, mid) >= k)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
