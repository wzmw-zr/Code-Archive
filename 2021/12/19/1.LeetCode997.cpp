/*************************************************************************
	> File Name: 1.LeetCode997.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月19日 星期日 09时15分40秒
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

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in_deg(n + 1, 0);
    vector<int> out_deg(n + 1, 0);
    for (auto &&x : trust) {
        in_deg[x[1]]++;
        out_deg[x[0]]++;
    }
    int ans = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (out_deg[i] == 0 && in_deg[i] == (n - 1)) {
            ans = i;
            cnt++;
        }
    }
    return cnt == 1 ? ans : -1;
}

int main() {
    return 0;
}
