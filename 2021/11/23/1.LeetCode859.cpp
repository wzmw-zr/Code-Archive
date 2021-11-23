/*************************************************************************
	> File Name: 1.LeetCode859.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月23日 星期二 08时25分56秒
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

bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (char c : s) cnt1[c - 'a']++;
    for (char c : goal) cnt2[c - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (cnt1[i] == cnt2[i]) continue;
        return false;
    }
    int inds = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == goal[i]) continue;
        inds++;
    }
    if (inds == 1 || inds > 2) return false;
    if (inds == 0) {
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] >= 2) return true;
        }
        return false;
    }
    return true;
}

int main() {
    return 0;
}
