/*************************************************************************
	> File Name: 3.LeetCode6111.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月03日 星期日 10时45分54秒
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
  vector<vector<int>> ans(m, vector<int>(n, -1));
  int l_x = 0, l_y = 0, r_x = m - 1, r_y = n - 1;
  while (head) {
    for (int i = l_y; i <= r_y && head; i++) {
      ans[l_x][i] = head->val;
      head = head->next;
    }
    for (int i = l_x + 1; i <= r_x && head; i++) {
      ans[i][r_y] = head->val;
      head = head->next;
    }
    for (int i = r_y - 1; head && i >= l_y; i--) {
      ans[r_x][i] = head->val;
      head = head->next;
    }
    for (int i = r_x - 1; head && i >= l_x + 1; i--) {
      ans[i][l_y] = head->val;
      head = head->next;
    }
    l_x++, l_y++, r_x--, r_y--;
  }
  return ans;
}

int main() {
  return 0;
}
