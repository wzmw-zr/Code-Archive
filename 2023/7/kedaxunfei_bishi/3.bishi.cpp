/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月29日 星期六 19时39分39秒
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
  int s;
  cin >> s;
  unordered_set<int> st(arr.begin(), arr.end());
  int cnt = 0;
  for (int x : arr) {
    if (x >= s)
      continue;
    if (st.count(s - x))
      cnt++;
    else
      cnt += 2;
  }
  cout << s - 1 - cnt << endl;
  return 0;
}
