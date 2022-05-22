/*************************************************************************
	> File Name: 3.LeetCode6076.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月22日 星期日 10时44分48秒
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

int minimumLines(vector<vector<int>>& stockPrices) {
  sort(stockPrices.begin(), stockPrices.end());
  int n = stockPrices.size();
  if (n == 1) return 0;
  int cnt = 1;
  for (int i = 2; i < n; i++) {
    long day1 = stockPrices[i - 2][0];
    long price1 = stockPrices[i - 2][1];
    long day2 = stockPrices[i - 1][0];
    long price2 = stockPrices[i - 1][1];
    long day3 = stockPrices[i][0];
    long price3 = stockPrices[i][1];
    if ((price2 - price1) * (day3 - day2) != (price3 - price2) * (day2 - day1)) cnt++;
    // long k1 = (price2 - price1) / (day2 - day1);
    // long k2 = (price3 - price2) / (day3 - day2);
    // if (k1 != k2) cnt++;
  }
  return cnt;
}


int main() {
  return 0;
}
