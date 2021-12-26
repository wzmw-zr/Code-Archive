/*************************************************************************
	> File Name: 4.LeetCode5498.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月26日 星期日 19时05分01秒
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
    int mmax = 0, mmin = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            mmax++;
            if (locked[i] == '1') mmin++;
            else mmin = mmin == 0 ? 1 : mmin - 1;
        } else {
            mmin = mmin == 0 ? 1 : mmin - 1;
            if (locked[i] == '1') mmax--;
            else mmax++;
        }
        if (mmax < mmin) return false;
    }
    return mmin == 0;
}

int main() {
    return 0;
}
