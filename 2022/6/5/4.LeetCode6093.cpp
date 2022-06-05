/*************************************************************************
	> File Name: 4.LeetCode6093.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月05日 星期日 10时45分38秒
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

class TextEditor {
public:
  string left;
  string right;

  TextEditor() {}

  void addText(string text) {
    left += text;
  }

  int deleteText(int k) {
    int cnt = 0;
    while (k && left.size()) {
      left.pop_back();
      k--;
      cnt++;
    }
    return cnt;
  }

  string cursorLeft(int k) {
    while (k && left.size()) {
      right += *left.rbegin();
      left.pop_back();
      k--;
    }
    int len = min(10, (int) left.size());
    return left.substr(left.size() - len);
  }

  string cursorRight(int k) {
    while (k && right.size()) {
      left += *right.rbegin();
      right.pop_back();
      k--;
    }
    int len = min(10, (int) left.size());
    return left.substr(left.size() - len);
  }
};


int main() {
  return 0;
}
