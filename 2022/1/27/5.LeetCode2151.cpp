/*************************************************************************
	> File Name: 5.LeetCode2151.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月27日 星期四 09时22分51秒
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

// TLE
int maximumGood(vector<vector<int>>& statements) {
    int n = statements.size();
    int origin = (1 << n) - 1;
    int state = (1 << n) - 1;
    int ans = 0;
    while (state) {
        vector<int> inds;
        // indices of digits 1 in `param: state`
        for (int i = 0; i < n; i++) {
            if (state & (1 << i)) {
                inds.push_back(i);
            }
        }
        int m = inds.size();
        int flag = 1;
        unordered_set<int> st_inds(inds.begin(), inds.end());
        // check each pair of index (i, j) in `param: inds`, 
        // whether has `statements[inds[i]][inds[j]] != 0`
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) {
                    continue;
                }
                if (statements[inds[j]][inds[i]] == 0) {
                    flag = 0;
                    break;
                }
            }
            for (int k = 0; k < n; k++) {
                if (statements[inds[i]][k] == 1 && !st_inds.count(k)) flag = 0;
            }
            if (!flag) break;
        }
        if (flag) {
            ans = max(ans, static_cast<int>(inds.size()));
        }
        state = origin & (state - 1);
    }
    return ans;
}

int main() {
    return 0;
}
