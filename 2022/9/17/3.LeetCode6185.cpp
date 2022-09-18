/*************************************************************************
	> File Name: 3.LeetCode6185.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月17日 星期六 22时40分49秒
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

int matchPlayersAndTrainers(vector<int>& _players, vector<int>& _trainers) {
  multiset<int> players(_players.begin(), _players.end());
  multiset<int> trainers(_trainers.begin(), _trainers.end());
  auto p_iter = players.begin();
  int cnt = 0;
  while (players.size() && trainers.size() && p_iter != players.end()) {
    auto t_iter = trainers.lower_bound(*p_iter);
    if (t_iter == trainers.end()) 
      break;
    p_iter = players.erase(p_iter);
    trainers.erase(t_iter);
    cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
