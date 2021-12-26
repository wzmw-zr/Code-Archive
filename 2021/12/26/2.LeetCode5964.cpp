/*************************************************************************
	> File Name: 2.LeetCode5964.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月26日 星期日 10时34分58秒
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

unordered_map<char, PII> mp = {{'L', PII(0, -1)}, {'R', PII(0, 1)}, {'U', PII(-1, 0)}, {'D', PII(1, 0)}};

int execute(int n, vector<int> &startPos, int ind, string &s) {
    int x = startPos[0], y = startPos[1];
    int m = s.size();
    for (int i = ind; i < m; i++) {
        x = x + mp[s[i]].first;
        y = y + mp[s[i]].second;
        if (x < 0 || x >= n || y < 0 || y >= n) return i - ind;
    }
    return m - ind;
}

vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    int m = s.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) ans.push_back(execute(n, startPos, i, s));
    return ans;
}

int main() {
    return 0;
}
