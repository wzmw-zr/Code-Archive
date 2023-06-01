/*************************************************************************
	> File Name: 1.LeetCode2517.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月01日 星期四 10时11分42秒
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

int maximumTastiness(vector<int>& price, int k) {
  int n = price.size();
  sort(price.begin(), price.end());
  int l = 0, r = price[n - 1] - price[0];
  while (l < r) {
    int mid = (l + r + 1) / 2;
    int cnt = 1;
    for (int i = 0; i < n; ) {
      int ind = i + 1;
      while (ind < n && price[ind] - price[i] < mid)
        ind++;
      if (ind < n)
        cnt++;
      i = ind;
    }
    if (cnt >= k)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
