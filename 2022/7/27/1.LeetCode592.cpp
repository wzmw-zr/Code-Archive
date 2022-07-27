/*************************************************************************
	> File Name: 1.LeetCode592.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月27日 星期三 09时24分58秒
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

struct Node {
  long flag;
  long numerator;
  long denominator;

  Node() = default;
  Node(long flag, long numerator, long denominator) : flag(flag), numerator(numerator), denominator(denominator) {}
};

long gcd(long x, long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

string fractionAddition(string expression) {
  int ind = 0;
  vector<Node> nodes;
  while (expression[ind]) {
    long flag = 1;
    if (expression[ind] == '-') {
      flag = -1;
      ind++;
    } else if (expression[ind] == '+') {
      flag = 1;
      ind++;
    }
    string numerator = "";
    while (expression[ind] && expression[ind] >= '0' && expression[ind] <= '9') 
      numerator += expression[ind++];
    ind++;

    string denominator = "";
    while (expression[ind] && expression[ind] >= '0' && expression[ind] <= '9') 
      denominator += expression[ind++];
    nodes.push_back(Node(flag, stol(numerator), stol(denominator)));
  }
  long num = 1;
  long sum = 0;
  for (long i = 1; i <= 9; i++) num *= i;
  for (auto && node : nodes) {
    node.numerator *= num / node.denominator;
    node.denominator = num;
    sum += node.numerator * node.flag;
  }
  long flag = sum >= 0 ? 1 : -1;
  sum = abs(sum);
  long x = gcd(sum, num);
  return (flag == -1 ? "-" : "") + to_string(sum / x) + "/" + to_string(num / x);
}

int main() {
  return 0;
}
