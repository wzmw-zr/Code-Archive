/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月20日 星期日 14时02分04秒
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
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int val = nums[n - 1];
  int left = INT32_MIN, right = INT32_MAX;
  for (int i = 0; i < n; i++) {
    if (nums[i] == val) {
      cout << "Congratulations! You guessed it right!" << endl;
    } else if (nums[i] > val) {
      if (nums[i] > right) {
        cout << "Are you kidding me?" << endl;
      } else {
        cout << "It's too big, please keep guessing!" << endl;
        right = nums[i] - 1;
      }
    } else {
      if (nums[i] < left) {
        cout << "Are you kidding me?" << endl;
      } else {
        cout << "It's too small, please keep guessing!" << endl;
        left = nums[i] + 1;
      }
    }
  }
  return 0;
}
