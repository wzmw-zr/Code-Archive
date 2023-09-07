/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月07日 星期四 19时19分25秒
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

void dfs(vector<int> &arr, vector<int> &check, vector<int> &prime, int &ans, int &n) {
  if (arr.size() == n) {
    ans++;
    return ;
  }
  for (int i = 1; i <= n; i++) {
    if (check[i])
      continue;
    if (arr.size() == 0) {
      check[i] = 1;
      arr.push_back(i);
      dfs(arr, check, prime, ans, n);
      check[i] = 0;
      arr.pop_back();
    } else {
      int sum = *arr.rbegin() + i;
      if (prime[sum])
        continue;
      check[i] = 1;
      arr.push_back(i);
      dfs(arr, check, prime, ans, n);
      check[i] = 0;
      arr.pop_back();
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> prime(110, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= 100; i++) {
    if (!prime[i])
      continue;
    for (int j = 2; i * j <= 100; j++)
      prime[i * j] = 0;
  }
  vector<int> arr;
  vector<int> check(n + 1, 0);
  int ans = 0;
  dfs(arr, check, prime, ans, n);
  cout << ans << endl;
  return 0;
}
