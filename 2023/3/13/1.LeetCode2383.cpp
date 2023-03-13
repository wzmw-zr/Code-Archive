/*************************************************************************
	> File Name: 1.LeetCode2383.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月13日 星期一 09时36分25秒
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

int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
  int ans = 0;
  int total_energy = 0;
  for (int x : energy)
    total_energy += x;
  ans += max(0, total_energy - initialEnergy + 1);
  for (int x : experience) {
    if (initialExperience <= x) {
      ans += x + 1 - initialExperience;
      initialExperience = x + 1;
    }
    initialExperience += x;
  }
  return ans;
}

int main() {
  return 0;
}
