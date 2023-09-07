/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月07日 星期四 19时33分28秒
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
  int n, m;
  cin >> n >> m;
  vector<string> matrix(n);
  for (int i = 0; i < n; i++)
    cin >> matrix[i];
  vector<int> c_y(m, 0), c_o(m, 0), c_u(m, 0);
  vector<int> r_y(n, 0), r_o(n, 0), r_u(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 'y')
        c_y[j]++, r_y[i]++;
      else if (matrix[i][j] == 'o')
        c_o[j]++, r_o[i]++;
      else if (matrix[i][j] == 'u')
        c_u[j]++, r_u[i]++;
    }
  }

  long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 'y') {
        ans += c_u[i] * r_o[j];
        ans += c_o[i] * r_u[j];
      } else if (matrix[i][j] == 'o') {
        ans += c_y[i] * r_u[j];
        ans += c_u[i] * r_y[j];
      } else if (matrix[i][j] == 'u') {
        ans += c_y[i] * r_o[j];
        ans += c_o[i] * r_y[j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
