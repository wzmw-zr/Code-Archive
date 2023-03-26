/*************************************************************************
	> File Name: 1.LeetCode6354.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月26日 星期日 10时34分10秒
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

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
  if (k <= numOnes) 
    return k;
  if (k > numOnes)
    k -= numOnes;
  if (k <= numZeros)
    return numOnes;
  if (k > numZeros)
    k -= numZeros;
  return numOnes - k;
}

int main() {
  return 0;
}
