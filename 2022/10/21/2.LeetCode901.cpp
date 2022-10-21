/*************************************************************************
	> File Name: 2.LeetCode901.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月21日 星期五 10时28分19秒
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

using PII = pair<int, int>;

class StockSpanner {
public:
  stack<PII> st;

  StockSpanner() {}

  int next(int price) {
    int cnt = 1;
    while (!st.empty() && st.top().first <= price) {
      cnt += st.top().second;
      st.pop();
    }
    st.push(PII(price, cnt));
    return st.top().second;
  }
};

int main() {
  return 0;
}
