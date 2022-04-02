/*************************************************************************
	> File Name: 1.LeetCode744.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月03日 星期日 00时06分54秒
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

char nextGreatestLetter(vector<char>& letters, char target) {
  int l = 0, r = letters.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (letters[mid] > target) r = mid;
    else l = mid + 1;
  }
  return letters[l] > target ? letters[l] : letters[0];
}

int main() {
  return 0;
}
