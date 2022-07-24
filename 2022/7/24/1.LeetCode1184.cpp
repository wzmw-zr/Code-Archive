/*************************************************************************
	> File Name: 1.LeetCode1184.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月24日 星期日 09时27分04秒
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

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
  int n = distance.size();
  int sum = 0, path = 0;
  for (int x : distance) sum += x;
  while (start != destination) {
    path += distance[start];
    start = (start + 1) % n;
  }
  return min(path, sum - path);
}

int main() {
  return 0;
}
