/*************************************************************************
	> File Name: 5.LeetCode6321.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 11时16分01秒
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

int findSmallestInteger(vector<int>& nums, int value) {
  unordered_map<int, int> mp;
  for (int x : nums)
    mp[((x % value) + value) % value]++;
  int round = 0;
  while (1) {
    for (int i = 0; i < value; i++) {
      if (!mp.count(i))
        return round * value + i;
      if (!(--mp[i]))
        mp.erase(i);
    }
    round++;
  }
  return -1;
}

int main() {
  return 0;
}
