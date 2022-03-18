/*************************************************************************
	> File Name: 1.LeetCode2043.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月18日 星期五 11时52分45秒
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

class Bank {
public:
  vector<long long> accounts;

  Bank(vector<long long>& balance) : accounts(move(balance)) {}

  bool transfer(int account1, int account2, long long money) {
    if (account1 <= 0 || account1 > accounts.size() || account2 <= 0 || account2 > accounts.size()) return false;
    if (accounts[account1 - 1] < money) return false;
    accounts[account1 - 1] -= money;
    accounts[account2 - 1] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    if (account <= 0 || account > accounts.size()) return false;
    accounts[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (account <= 0 || account > accounts.size()) return false;
    if (accounts[account - 1] < money) return false;
    accounts[account - 1] -= money;
    return true;
  }
};

int main() {
  return 0;
}
