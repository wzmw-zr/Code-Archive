/*************************************************************************
	> File Name: 2.LeetCode6062.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月16日 星期六 22时36分38秒
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

class ATM {
public:
  vector<long> vals;
  vector<long> cnts;
  ATM() : vals({20, 50, 100, 200, 500}), cnts(vector<long>(5, 0)) {}

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < 5; i++) cnts[i] += banknotesCount[i];
  }

  vector<int> withdraw(int amount) {
    vector<int> ans(5);
    for (int i = 4; i >= 0; i--) {
      long t = min(amount / vals[i], cnts[i]);
      amount -= t * vals[i];
      ans[i] = t;
    }
    if (amount == 0) {
      for (int i = 0; i <= 4; i++) cnts[i] -= ans[i];
      return ans;
    }
    return {-1};
  }
};

int main() {
  return 0;
}
