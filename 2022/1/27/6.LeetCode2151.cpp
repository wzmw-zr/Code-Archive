/*************************************************************************
	> File Name: 6.LeetCode2151.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月27日 星期四 10时19分43秒
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

int maximumGood(vector<vector<int>>& statements) {
    int n = statements.size();
    int ans = 0;
    for (int mask = (1 << n) - 1, state = (1 << n) - 1; state > 0; state = mask & (state - 1)) {
        auto check = [&](){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (statements[i][j] == 1) {
                        if ((state & (1 << i)) && !(state & (1 << j))) {
                            return false;
                        }
                    }
                    if (statements[i][j] == 0) {
                        if ((state & (1 << i)) && (state & (1 << j))) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }();
        if (check) {
            ans = max(ans, __builtin_popcount(state));
        }
    }
    return ans;
}

int main() {
    return 0;
}
