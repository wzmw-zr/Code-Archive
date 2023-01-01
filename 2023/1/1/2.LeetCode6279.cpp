/*************************************************************************
	> File Name: 2.LeetCode6279.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月01日 星期日 10时34分53秒
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

int distinctPrimeFactors(vector<int>& nums) {
  vector<int> primes(1010, -1);
  for (int i = 2; i <= 1000; i++) {
    if (primes[i] == -1) {
      primes[i] = i;
      for (int j = 2; i * j <= 1000; j++)
        primes[i * j] = i;
    }
  }
  unordered_set<int> st;
  for (int x : nums) {
    while (x != 1) {
      st.insert(primes[x]);
      x /= primes[x];
    }
  }
  return st.size();
}

int main() {
  return 0;
}
