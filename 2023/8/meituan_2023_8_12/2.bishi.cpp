/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月12日 星期六 10时05分27秒
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
  vector<long> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int x, y;
  cin >> x >> y;
  x = (x - 1 + n) % n;
  y = (y - 1 + n) % n;
  long sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  long path = 0;
  int ind = x;
  while (ind != y) {
    path += arr[ind];
    ind = (ind + 1) % n;
  }
  cout << min(path, sum - path) << endl;
  return 0;
}
