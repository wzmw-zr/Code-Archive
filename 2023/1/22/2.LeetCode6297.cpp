/*************************************************************************
	> File Name: 2.LeetCode6297.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月22日 星期日 10时34分00秒
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

vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
  sort(score.begin(), score.end(), [&](vector<int> &a, vector<int> &b){
    return a[k] > b[k];
  });
  return score;
}

int main() {
  return 0;
}
