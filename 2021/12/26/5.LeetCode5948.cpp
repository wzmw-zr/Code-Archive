/*************************************************************************
	> File Name: 5.LeetCode5948.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月26日 星期日 21时19分44秒
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

bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n & 1) return false;
    int left = 0, right = 0, left_can_change = 0, right_can_change = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
            if (locked[i] == '0') left_can_change++;
        } else {
            right++;
            if (locked[i] == '0') right_can_change++;
        }
        if (left < right) {
            if (!right_can_change) return false;
            left++, left_can_change++;
            right--, right_can_change--;
        }
    }
    left = 0, right = 0, left_can_change = 0, right_can_change = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
            if (locked[i] == '0') left_can_change++;
        } else {
            right++;
            if (locked[i] == 0) right_can_change++;
        }
        if (right < left) {
            if (!left_can_change) return false;
            right++, right_can_change++;
            left--, left_can_change--;
        }
    }
    return true;
}

int main() {
    return 0;
}
