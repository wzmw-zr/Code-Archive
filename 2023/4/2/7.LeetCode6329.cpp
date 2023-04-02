/*************************************************************************
	> File Name: 7.LeetCode6329.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 14时25分35秒
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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

long long makeSubKSumEqual(vector<int>& arr, int k) {
  int n = arr.size();
  k = gcd(n, k);
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    vector<int> nums;
    for (int j = i; j < n; j += k)
      nums.push_back(arr[j % n]);
    sort(nums.begin(), nums.end());
    int m = nums.size();
    int mid = nums[(m + 1) / 2 - 1];
    for (int i = 0; i < m; i++)
      sum += 1L * abs(mid - nums[i]);
  }
  return sum;
}

int main() {
  return 0;
}
