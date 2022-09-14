/*************************************************************************
	> File Name: 1.LeetCode1619.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月14日 星期三 09时19分37秒
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

double trimMean(vector<int>& arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  double sum = 0;
  for (int i = n / 20; i < n * 19 / 20; i++)
    sum += arr[i];
  return sum / (n * 9 / 10);
}

int main() {
  return 0;
}
