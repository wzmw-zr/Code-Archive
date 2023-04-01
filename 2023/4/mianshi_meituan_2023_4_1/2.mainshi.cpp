/*************************************************************************
	> File Name: 2.mainshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 10时27分12秒
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

int main() {
  int n;
  cin >> n;
  vector<long> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  sort(nums.begin(), nums.end());
  long ans = 0;
  for (int i = 0; i < n - 1; i++)
    ans += abs(nums[i + 1] - nums[i]);
  cout << ans << endl;
  return 0;
}
