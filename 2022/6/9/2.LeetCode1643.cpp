/*************************************************************************
	> File Name: 2.LeetCode1643.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月09日 星期四 10时16分52秒
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

string kthSmallestPath(vector<int>& destination, int k) {
  auto permute = [](vector<int> &cnt) -> long {
    long total = 1;
    for (long i = max(cnt[0], cnt[1]) + 1; i <= (cnt[0] + cnt[1]); i++) total = total * i;
    for (long i = 1; i <= min(cnt[0], cnt[1]); i++) total /= i;
    return total;
  };
  string ans = "";
  while (k) {
    if (destination[0] == 0) {
      for (int i = 0; i < destination[1]; i++) ans += "H";
      break;
    }
    if (destination[1] == 0) {
      for (int i = 0; i < destination[0]; i++) ans += "V";
      break;
    }
    destination[1]--;
    int cnt = permute(destination);
    if (k <= cnt) {
      ans += "H";
    } else {
      destination[1]++;
      destination[0]--;
      k -= cnt;
      ans += "V";
    } 
  }
  return ans;
}

int main() {
  return 0;
}
