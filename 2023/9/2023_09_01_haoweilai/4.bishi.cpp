/*************************************************************************
	> File Name: 4.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月01日 星期五 19时44分52秒
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
#include <numeric>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> prime(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    if (!prime[i])
      continue;
    for (int j = 2; i * j <= n; j++)
      prime[i * j] = 0;
  }
  prime[0] = prime[1] = 0;
  cout << accumulate(prime.begin(), prime.end(), 0) << endl;
  return 0;
}
