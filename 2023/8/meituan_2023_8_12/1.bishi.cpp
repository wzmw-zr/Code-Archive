/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月12日 星期六 10时01分33秒
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
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int x, y;
  cin >> x >> y;
  int flag = 0;
  for (int i = 0; i < n - 1 && !flag; i++) {
    if ((arr[i] == x && arr[i + 1] == y) || (arr[i] == y && arr[i + 1] == x))
      flag = 1;
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
