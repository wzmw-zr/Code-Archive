/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月23日 星期六 14时02分12秒
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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    if (n & 1) {
      cout << "YES" << endl;
    } else {
      vector<int> even, odd;
      for (int i = 0; i < n; i++) {
        if (i & 1)
          odd.push_back(nums[i]);
        else
          even.push_back(nums[i]);
      }
      sort(even.begin(), even.end());
      sort(odd.begin(), odd.end());
      vector<int> temp;
      for (int i = 0; i < n / 2; i++) {
        temp.push_back(even[i]);
        temp.push_back(odd[i]);
      }
      int flag = 0;
      for (int i = 0; i < n - 1; i++) {
        if (temp[i] <= temp[i + 1])
          continue;
        flag = 1;
        break;
      }
      cout << (flag ? "NO" : "YES") << endl;
    }
  }
  return 0;
}
