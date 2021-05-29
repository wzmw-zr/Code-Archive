/*************************************************************************
	> File Name: 6.LeetCode5757.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月29日 星期六 22时50分52秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

int calculate(vector<vector<int>> &grid, int x, int y, int l) {
    set<PII> st;
    for (int i = 0; i < (l - 1); i++) st.insert(PII(x - i, y + i));
    for (int i = 0; i < (l - 1); i++) st.insert(PII(x - l + 1 + i, y + l - 1 + i));
    for (int i = 0; i < (l - 1); i++) st.insert(PII(x + i, y + 2 * l - 2 - i));
    for (int i = 0; i < (l - 1); i++) st.insert(PII(x + l - 1 - i, y + l - 1 - i));
    int ans = 0;
    for (auto x : st)  ans += grid[x.first][x.second];
    return ans;
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    set<int> st;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            st.insert(grid[i][j]);
    for (int l = 2; l <= min(m, n); l++) {
        for (int i = 0; i < m; i++) {
            if (((i - l + 1) < 0) || ((i + l - 1) >= m)) continue;
            for (int j = 0; (j + 2 * l - 2) < n; j++) {
                st.insert(calculate(grid, i, j, l));
            }
        }
    }
    vector<int> ans;
    int cnt = min(3, (int) st.size());
    auto iter = prev(st.end());
    for (int i = 0; i < cnt; i++) {
        ans.push_back(*iter);
        iter = prev(iter);
    }
    return ans;
}

int main() {
    return 0;
}
