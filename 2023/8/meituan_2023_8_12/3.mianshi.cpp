/*************************************************************************
	> File Name: 3.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月12日 星期六 10时10分32秒
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
#include <cstdint>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<long>> arr(n, vector<long>(m));
  vector<long> rows(n + 1, 0);
  vector<long> cols(m + 1, 0);
  long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      rows[i + 1] += arr[i][j];
      cols[j + 1] += arr[i][j];
      sum += arr[i][j];
    }
  }
  long ans = INT32_MAX;
  for (int i = 0; i < n; i++) {
    rows[i + 1] += rows[i];
    ans = min(ans, abs(sum - rows[i + 1] * 2));
  }
  for (int i = 0; i < m; i++) {
    cols[i + 1] += cols[i];
    ans = min(ans, abs(sum - cols[i + 1] * 2));
  }
  cout << ans << endl;
  return 0;
}
