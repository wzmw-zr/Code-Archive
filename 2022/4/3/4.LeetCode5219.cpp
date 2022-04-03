/*************************************************************************
	> File Name: 4.LeetCode5219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月03日 星期日 10时50分01秒
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

long long check(vector<long long> &candies, long long num) {
  long long ans = 0;
  for (auto x : candies) ans += x / num;
  return ans;
}

int maximumCandies(vector<int>& candies, long long k) {
  long long l = 0, r = 1e12;
  vector<long long> temp(candies.size());
  for (int i = 0; i < candies.size(); i++) temp[i] = candies[i];
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(temp, mid) >= k) l = mid;
    else r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
