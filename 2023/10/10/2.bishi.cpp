/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月10日 星期二 19时37分19秒
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
  long n, l, r;
  cin >> n >> l >> r;
  if (n < l) {
    cout << -1 << endl;
    return 0;
  }
  int rest = n % r;
  int cnt = n / r;
  int mmax = INT32_MIN, mmin = INT32_MAX;
  if (rest + cnt * (r - l) >= l) {
    mmax = max(mmax, cnt + (rest == 0 ? 0 : 1));
    mmin = min(mmin, cnt + (rest == 0 ? 0 : 1));
  }
  rest = n % l;
  cnt = n / l;
  if (rest <= cnt * (r - l)) {
    mmax = max(mmax, cnt);
    mmin = min(mmin, cnt);
  }
  cout << (mmin == INT32_MAX ? -1 : mmin) << " " << (mmax == INT32_MIN ? -1 : mmax) << endl;
  return 0;
}
