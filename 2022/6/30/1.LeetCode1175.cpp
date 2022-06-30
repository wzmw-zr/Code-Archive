/*************************************************************************
	> File Name: 1.LeetCode1175.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月30日 星期四 08时53分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long MOD = 1e9 + 7;

long permute(int x) {
  long ans = 1;
  for (long i = 1; i <= x; i++) ans = ans * i % MOD;
  return ans;
}

int numPrimeArrangements(int n) {
  vector<int> prime(n + 5, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!prime[i]) continue;
    for (int j = 2; i * j <= n; j++) prime[i * j] = 0;
  }
  for (int i = 1; i <= n; i++) prime[i] += prime[i - 1];
  long ans = permute(prime[n]) * permute(n - prime[n]) % MOD;
  return ans;
}

int main() {
  return 0;
}
