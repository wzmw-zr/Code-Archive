/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月13日 星期五 19时33分18秒
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
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> is_prime(n + 10, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i])
      continue;
    for (int j = 2; i * j <= n; j++)
      is_prime[i * j] = 0;
  }
  double sum = 0;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i])
      sum += i;
  }
  printf("%.4f", sqrt(sum));
  return 0;
}
