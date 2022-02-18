/*************************************************************************
	> File Name: 1.LeetCode969.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月19日 星期六 00时11分54秒
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

void reverse(vector<int> &arr, int ind) {
  int l = 0, r = ind;
  while (l < r) {
    swap(arr[l++], arr[r--]);
  }
}

int find_first_gt(vector<int> &arr, int val, int l, int r) {
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] > val) 
      r = mid;
    else 
      l = mid + 1;
  }
  return l;
}

vector<int> pancakeSort(vector<int>& arr) {
  vector<int> ans;
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1])
      continue;
    int t = find_first_gt(arr, arr[i], 0, i - 1);
    ans.push_back(i + 1);
    ans.push_back(i - t + 1);
    ans.push_back(i - t);
    ans.push_back(i + 1);

    reverse(arr, i);
    reverse(arr, i - t);
    reverse(arr, i - t - 1);
    reverse(arr, i);
  }
  return ans;
}

int main() {
  return 0;
}
