/*************************************************************************
	> File Name: 1.LeetCode537.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月25日 星期五 00时08分51秒
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

struct Comp {
  int real;
  int img;
  
  Comp() = default;
  Comp(int real, int img) : real(real), img(img) {}
  Comp(string num) : real(0), img(0) {
    int ind = 0;
    while (num[ind] != '+') ind++;
    real = stoi(num.substr(0, ind));
    img = stoi(num.substr(ind + 1, num.size() - ind - 2));
  }

  Comp operator*(const struct Comp &that) const {
    int x = this->real * that.real - this->img * that.img;
    int y = this->real * that.img + this->img * that.real;
    return Comp(x, y);
  }

  string tostring() {
    return to_string(real) + "+" + to_string(img) + "i";
  }
};

string complexNumberMultiply(string num1, string num2) {
  Comp c1(num1), c2(num2);
  Comp mul = c1 * c2;
  return mul.tostring();
}

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  cout << complexNumberMultiply(num1, num2) << endl;
  return 0;
}
