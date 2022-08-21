/*************************************************************************
	> File Name: 2.LeetCode6152.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月21日 星期日 10时31分21秒
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
  int n = energy.size();
  int curr_energy = initialEnergy;
  int curr_exp = initialExperience;
  for (int i = 0; i < n; i++) {
    if (curr_energy <= energy[i]) {
      ans += energy[i] + 1 - curr_energy;
      curr_energy = energy[i] + 1;
    }
    if (curr_exp <= experience[i]) {
      ans += experience[i] + 1 - curr_exp;
      curr_exp = experience[i] + 1;
    }
    curr_energy -= energy[i];
    curr_exp += experience[i];
  }
  return ans;
}

int main() {
  return 0;
}
