/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月29日 星期六 19时32分59秒
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

int main() {
  int n;
  cin >> n;
  vector<long> arr1(n), arr2(n);
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int i = 0; i < n; i++)
    cin >> arr2[i];
  long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min({
      abs(arr1[i] - arr2[i]),
      abs(arr1[i] + arr2[i]),
      abs(-1 * arr1[i] - arr2[i]),
      abs(-1 * arr1[i] + arr2[i])
    });
  }
  cout << ans << endl;
  return 0;
}
