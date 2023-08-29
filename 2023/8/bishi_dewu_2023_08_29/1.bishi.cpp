/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月29日 星期二 10时15分59秒
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

long MOD = 1e9 + 7;

int main() {
  long N, A, B;
  cin >> N >> A >> B;
  vector<long> nums(N + 10, 0);
  nums[1] = A, nums[2] = B;
  long pre = A + B;
  for (int i = 3; i <= N; i++) {
    nums[i] = (pre + 1) % MOD;
    pre = (pre * 2 + 1) % MOD;
  }
  cout << pre << endl;
  return 0;
}
