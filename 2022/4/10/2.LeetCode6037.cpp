/*************************************************************************
	> File Name: 2.LeetCode6037.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月10日 星期日 10时34分28秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int largestInteger(int num) {
  vector<int> digits;
  do {
    digits.push_back(num % 10);
    num /= 10;
  } while (num);
  vector<int> odd, even;
  vector<int> odd_inds, even_inds;
  for (int i = 0; i < digits.size(); i++) {
    if (digits[i] & 1) {
      odd.push_back(digits[i]);
      odd_inds.push_back(i);
    } else {
      even.push_back(digits[i]);
      even_inds.push_back(i);
    }
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  for (int i = 0; i < odd.size(); i++) digits[odd_inds[i]] = odd[i];
  for (int i = 0; i < even.size(); i++) digits[even_inds[i]] = even[i];
  reverse(digits.begin(), digits.end());
  int ans = 0;
  for (int x : digits) ans = ans * 10 + x;
  return ans;
}

int main() {
  int num;
  cin >> num;
  cout << largestInteger(num) << endl;
  return 0;
}
