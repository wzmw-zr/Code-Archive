/*************************************************************************
	> File Name: 1.LeetCode1994.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月22日 星期二 00时16分02秒
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

long MOD = 1e9 + 7;

unordered_set<int> valid = {1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30};
unordered_map<int, vector<int>> resolve = {
  {2, {2}},
  {3, {3}},
  {5, {5}},
  {6, {2, 3}},
  {7, {7}},
  {10, {2, 5}},
  {11, {11}},
  {13, {13}},
  {14, {2, 7}},
  {15, {3, 5}},
  {17, {17}},
  {19, {19}},
  {21, {3, 7}},
  {22, {2, 11}},
  {23, {23}},
  {26, {2, 13}},
  {29, {29}}, 
  {30, {2, 3, 5}},
};

vector<long> cnts = vector<long>(31, 0);


int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

long calculate(vector<int> &nums) {
  long ans = 0;
  int n = nums.size();
  for (int i = 0; i < (1 << n); i++) {
    long temp = 1;
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) continue;
      temp = temp * cnts[nums[j]] % MOD;
    }
    ans = (ans + temp) % MOD;
  }
  return ans;
}

long quick_pow(long x, long p) {
  long base = x;
  long ans = 1;
  while (p) {
    if (p & 1) {
      ans = ans * base % MOD;
    }
    base = base * base % MOD;
    p >>= 1;
  }
  return ans;
}

int numberOfGoodSubsets(vector<int>& nums) {
  for (int x : nums) cnts[x]++;
  vector<int> one;
  vector<int> two;
  vector<int> three;
  for (int i = 2; i <= 30; i++) {
    if (cnts[i] == 0 || !valid.count(i)) continue;
    switch (resolve[i].size()) {
      case 1 : one.push_back(i); break;
      case 2 : two.push_back(i); break;
      case 3 : three.push_back(i); break;
    }
  }
  long ans = 0;
  ans = (ans + calculate(one) - 1 + MOD) % MOD;
  for (int x : two) {
    vector<int> temp;
    for (int y : one) {
      if (gcd(x, y) == 1) temp.push_back(y);
    }
    ans = (ans + (calculate(temp) * cnts[x] % MOD)) % MOD;
  }
  for (int i = 0; i < two.size(); i++) {
    for (int j = i + 1; j < two.size(); j++) {
      if (gcd(two[i], two[j]) != 1) continue;
      vector<int> temp;
      for (int z : one) {
        if (gcd(z, two[i]) == 1 && gcd(z, two[j]) == 1) temp.push_back(z);
      }
      ans = (ans + ((calculate(temp) * cnts[two[i]] % MOD) * cnts[two[j]] % MOD)) % MOD;
    }
  }
  for (int x : three) {
    vector<int> temp;
    for (int y : one) {
      if (gcd(x, y) == 1) temp.push_back(y);
    }
    ans = (ans + (calculate(temp) * cnts[x] % MOD)) % MOD;
  }
  ans = (ans * quick_pow(2, cnts[1])) % MOD;
  return ans;
}

int main() {
  return 0;
}
