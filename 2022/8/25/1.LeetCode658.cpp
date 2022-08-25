/*************************************************************************
	> File Name: 1.LeetCode658.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月25日 星期四 09时32分26秒
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

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (arr[mid] <= x) 
      l = mid;
    else
      r = mid - 1;
  }
  r++;
  vector<int> ans;
  while (k && (l >= 0 || r < n)) {
    if (l >= 0 && r < n) {
      if (abs(arr[l] - x) <= abs(arr[r] - x)) {
        ans.push_back(arr[l--]);
      } else {
        ans.push_back(arr[r++]);
      }
    } else if (l >= 0) {
      ans.push_back(arr[l--]);
    } else {
      ans.push_back(arr[r++]);
    }
    k--;
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  return 0;
}
